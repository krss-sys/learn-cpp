#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>
#include <iostream>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <vector>

constexpr uint32_t kMaxFrameSize = 1 << 20;

class AetherClient {
   private:
    int fd_ = -1;

   public:
    AetherClient(const std::string& ip, int port) {
        fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
        if (fd_ == -1) {
            throw std::runtime_error("Loi socket: " + std::string(std::strerror(errno)));
        }

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

        if (::connect(fd_, (sockaddr*)&addr, sizeof(addr)) == -1) {
            ::close(fd_);
            throw std::runtime_error("Loi connect: " + std::string(strerror(errno)));
        }
    }

    ~AetherClient() {
        if (fd_ >= 0) {
            ::close(fd_);
        }
    }

    AetherClient(const AetherClient&) = delete;
    AetherClient& operator=(const AetherClient&) = delete;

    bool send_frame(std::span<const uint8_t> payload) {
        uint32_t len = payload.size();
        uint32_t lenN = htonl(len);

        if (!send_all(&lenN, 4)) return false;
        if (!send_all(payload.data(), payload.size())) return false;

        return true;
    }

    std::optional<std::vector<uint8_t>> recv_frame() {
        uint32_t lenN;
        if (!recv_exact(&lenN, 4)) return std::nullopt;

        uint32_t len = ntohl(lenN);

        if (len > kMaxFrameSize) return std::nullopt;

        std::vector<uint8_t> payload(len);
        if (len > 0 && !recv_exact(payload.data(), len)) return std::nullopt;

        return payload;
    }

   private:
    bool send_all(const void* data, size_t len) {
        const char* ptr = static_cast<const char*>(data);
        size_t total = 0;

        while (total < len) {
            ssize_t n = ::send(fd_, ptr + total, len - total, MSG_NOSIGNAL);
            if (n > 0)
                total += n;
            else if (n < 0) {
                if (errno == EINTR) continue;
                return false;
            } else {
                return false;
            }
        }
        return true;
    }

    bool recv_exact(void* buf, size_t n) {
        char* ptr = static_cast<char*>(buf);
        size_t left = n;

        while (left > 0) {
            ssize_t r = ::recv(fd_, ptr, left, 0);
            if (r > 0) {
                left -= r;
                ptr += r;
            } else if (r == 0) {
                return false;
            } else {
                if (errno == EINTR) continue;
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    std::string ip = "127.0.0.1";
    int port = 8080;

    if (argc >= 3) {
        ip = argv[1];
        port = std::stoi(argv[2]);
    }

    try {
        std::cout << "Ket noi den " << ip << ": " << port << "\n";
        AetherClient client(ip, port);
        std::cout << "Da ket noi\n";

        std::string msg = "Hello";

        std::span<const uint8_t> payload(reinterpret_cast<const uint8_t*>(msg.data()), msg.size());
        client.send_frame(payload);
        std::cout << "Da gui: " << msg << "\n";

        auto response = client.recv_frame();
        if (response) {
            std::string resp(response->begin(), response->end());
            std::cout << "Nhan: " << resp << "\n";
        } else {
            std::cout << "Khong nhan duoc frame\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << "\n";
        return 1;
    }
    return 0;
}