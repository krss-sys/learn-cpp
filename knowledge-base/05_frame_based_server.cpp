#include <iostream>
#include <vector>
#include <cstring>
#include <optional>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

constexpr uint32_t kMaxFrameSize = 1 << 20;

// ==================== FRAMEDECODER (đã học) ====================
class FrameDecoder {
private:
    vector<uint8_t> buf_;
    bool error_ = false;

public:
    void feed(const uint8_t* data, size_t n) {
        if (error_) return;
        buf_.insert(buf_.end(), data, data + n);
    }

    optional<vector<uint8_t>> next() {
        if (error_) return nullopt;
        if (buf_.size() < 4) return nullopt;

        uint32_t len = 0;
        memcpy(&len, buf_.data(), 4);
        len = ntohl(len);

        if (len > kMaxFrameSize) {
            error_ = true;
            return nullopt;
        }

        size_t total = 4 + len;
        if (buf_.size() < total) return nullopt;

        vector<uint8_t> payload(buf_.begin() + 4, buf_.begin() + total);
        buf_.erase(buf_.begin(), buf_.begin() + total);
        return payload;
    }

    bool has_error() const { return error_; }
};

// ==================== I/O AN TOÀN (đã học) ====================
bool send_all(int fd, const void* data, size_t len) {
    const char* ptr = static_cast<const char*>(data);
    size_t total_sent = 0;

    while (total_sent < len) {
        ssize_t n = ::send(fd, ptr + total_sent, len - total_sent, MSG_NOSIGNAL);
        if (n > 0) total_sent += static_cast<size_t>(n);
        else if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        }
        else return false;
    }
    return true;
}

ssize_t recv_some(int fd, void* buf, size_t cap) {
    while (true) {
        ssize_t n = ::recv(fd, buf, cap, 0);
        if (n < 0 && errno == EINTR) continue;
        return n;
    }
}

// ==================== ENCODE FRAME (đã học) ====================
vector<uint8_t> encode_frame(const vector<uint8_t>& payload) {
    uint32_t len = payload.size();
    uint32_t lenN = htonl(len);

    vector<uint8_t> frame;
    const uint8_t* lenBytes = reinterpret_cast<const uint8_t*>(&lenN);
    for (int i = 0; i < 4; i++) frame.push_back(lenBytes[i]);
    frame.insert(frame.end(), payload.begin(), payload.end());
    return frame;
}

// ==================== XỬ LÝ CLIENT ====================
void handle_connection(int clientFd) {
    FrameDecoder decoder;
    uint8_t buf[4096];

    while (true) {
        ssize_t n = recv_some(clientFd, buf, sizeof(buf));

        if (n > 0) {
            decoder.feed(buf, static_cast<size_t>(n));

            // Cắt từng frame ra xử lý
            while (auto frame = decoder.next()) {
                // Chuyển vector<uint8_t> sang string để in
                string payload_str(frame->begin(), frame->end());
                cout << "Nhan frame: " << payload_str << endl;

                // Gửi trả lại frame đã encode
                auto encoded = encode_frame(*frame);
                if (!send_all(clientFd, encoded.data(), encoded.size())) {
                    cerr << "Loi gui" << endl;
                    return;
                }
            }

            // Kiểm tra lỗi DoS
            if (decoder.has_error()) {
                cerr << "[WARN] Frame qua lon. Dong ket noi." << endl;
                return;
            }
        }
        else if (n == 0) {
            cout << "Client dong ket noi." << endl;
            return;
        }
        else {
            cerr << "Recv error: " << strerror(errno) << endl;
            return;
        }
    }
}

// ==================== MAIN ====================
int main() {
    int serverFd = ::socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    ::setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    ::bind(serverFd, (sockaddr*)&addr, sizeof(addr));
    ::listen(serverFd, 5);

    cout << "Server dang chay tren port 8080..." << endl;

    while (true) {
        int clientFd = ::accept(serverFd, NULL, NULL);
        if (clientFd == -1) continue;

        cout << "Client ket noi!" << endl;

        // Xử lý trong thread mới (dùng kiến thức đã học)
        // Ở đây chỉ demo 1 client, nên gọi trực tiếp
        handle_connection(clientFd);
        ::close(clientFd);
    }

    ::close(serverFd);
    return 0;
}