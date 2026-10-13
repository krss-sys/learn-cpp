#include <arpa/inet.h>

#include <cstdint>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

constexpr uint32_t kMaxFrameSize = 1 << 20;

class FrameDecoder {
   private:
    std::vector<uint8_t> buf_;
    bool error_ = false;

   public:
    void feed(const uint8_t* data, size_t n) {
        if (error_) return;
        buf_.insert(buf_.end(), data, data + n);
    }

    std::optional<std::vector<uint8_t>> next() {
        if (error_) return std::nullopt;
        if (buf_.size() < 4) return std::nullopt;

        uint32_t len = 0;
        memcpy(&len, buf_.data(), 4);
        len = ntohl(len);

        if (len > kMaxFrameSize) {
            error_ = true;
            return std::nullopt;
        }

        size_t total = 4 + len;
        if (buf_.size() < total) {
            return std::nullopt;
        }

        std::vector<uint8_t> payload(buf_.begin() + 4, buf_.begin() + total);
        buf_.erase(buf_.begin(), buf_.begin() + total);
        return payload;
    }

    bool has_error() const { return error_; }
};

std::vector<uint8_t> encode_frame(const std::string& msg) {
    uint32_t len = msg.size();
    uint32_t lenN = htonl(len);

    std::vector<uint8_t> frame;
    const uint8_t* lenBytes = reinterpret_cast<const uint8_t*>(&lenN);
    for (int i = 0; i < 4; i++) frame.push_back(lenBytes[i]);
    for (char c : msg) frame.push_back(static_cast<uint8_t>(c));
    return frame;
}

int main() {
    std::cout << "=== TEST 1: FRAME BINH THUONG ===\n";
    FrameDecoder decode;
    auto f1 = encode_frame("hello");
    decode.feed(f1.data(), f1.size());

    if (auto p = decode.next()) {
        std::cout << "Frame: ";
        for (uint8_t b : *p) {
            std::cout << (char)b;
        }
        std::cout << "\n";
    }

    if (decode.has_error()) {
        std::cout << "CO LOI!!!\n";
    } else {
        std::cout << "Khong co loi\n";
    }

    std::cout << "\n=== TEST 2: FRAME DOC HAI (len qua lon) ===\n";
    FrameDecoder decoder2;

    // Tạo frame giả có len = 0xFFFFFFFF
    std::vector<uint8_t> badFrame = {0xFF, 0xFF, 0xFF, 0xFF, 'a', 'b'};
    decoder2.feed(badFrame.data(), badFrame.size());

    auto p = decoder2.next();
    if (!p) {
        std::cout << "Khong co frame (dung nhu mong doi)." << std::endl;
    }

    if (decoder2.has_error()) {
        std::cout << "Phat hien loi: len qua lon!" << std::endl;
    }

    return 0;
}