#include <arpa/inet.h>

#include <cstdint>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

constexpr uint32_t kMaxFrameSize = 1 << 20;

class FrameDecode {
   private:
    std::vector<uint8_t> buf_;
    bool error_ = false;

   public:
    void feed(const uint8_t* data, size_t n) { buf_.insert(buf_.end(), data, data + n); }

    std::optional<std::vector<uint8_t>> next() {
        if (buf_.size() < 4) return std::nullopt;

        uint32_t len = 0;
        std::memcpy(&len, buf_.data(), 4);
        len = ntohl(len);

        if (len > kMaxFrameSize) {
            error_ = true;
            return std::nullopt;
        }

        size_t total = 4 + len;
        if (buf_.size() < total) return std::nullopt;

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

void inPayload(const std::vector<uint8_t>& p) {
    for (uint8_t b : p) std::cout << (char)b;
}

int main() {
    std::cout << "== TEST 1: 3 FRAME DINH CHUM ===\n";
    auto f1 = encode_frame("hello");
    auto f2 = encode_frame("world");
    auto f3 = encode_frame("good");

    std::vector<uint8_t> bigData;
    bigData.insert(bigData.end(), f1.begin(), f1.end());
    bigData.insert(bigData.end(), f2.begin(), f2.end());
    bigData.insert(bigData.end(), f3.begin(), f3.end());

    FrameDecode decode;
    decode.feed(bigData.data(), bigData.size());

    while (auto p = decode.next()) {
        std::cout << "Frame: ";
        inPayload(*p);
        std::cout << "\n";
    }

    std::cout << "\n=== TEST 2: FEED TUNG BYTE ===\n";
    FrameDecode decode2;
    auto f4 = encode_frame("abc");
    for (uint8_t b : f4) {
        decode2.feed(&b, 1);
        if (auto p = decode2.next()) {
            std::cout << "Frame: ";
            inPayload(*p);
            std::cout << "\n";
        }
    }

    return 0;
}