#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>

std::vector<uint8_t> encode_frame(const std::string& msg) {
    uint32_t len = msg.size();
    uint32_t lenN = htonl(len);

    std::vector<uint8_t> frame;
    const uint8_t* lenBytes = reinterpret_cast<const uint8_t*>(&lenN);
    for (int i = 0; i < 4; i++) {
        frame.push_back(lenBytes[i]);
    }
    for (const char& c : msg) {
        frame.push_back(static_cast<uint8_t>(c));
    }
    return frame;
}

bool send_all(int fd, const void* data, size_t len) {
    const char* ptr = static_cast<const char*>(data);
    size_t total = 0;

    while (total < len) {
        ssize_t n = ::send(fd, ptr + total, len - total, MSG_NOSIGNAL);
        if (n > 0) {
            total += static_cast<size_t>(n);
        } else if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        } else {
            return false;
        }
    }
    return true;
}

int connect_to_server(const std::string& ip, int port) {
    int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        std::cerr << "Loi socket: " << strerror(errno) << "\n";
        return -1;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    if (::connect(fd, (sockaddr*)&addr, sizeof(addr)) == -1) {
        std::cerr << "Loi connect: " << strerror(errno) << "\n";
        ::close(fd);
        return -1;
    }
    return fd;
}

void test_sticky(int fd) {
    std::cout << "\n=== KICH BAN 1: DINH GOI ===\n";

    auto f1 = encode_frame("Hello A");
    auto f2 = encode_frame("System");
    auto f3 = encode_frame("C++20");

    std::vector<uint8_t> big;
    big.insert(big.end(), f1.begin(), f1.end());
    big.insert(big.end(), f2.begin(), f2.end());
    big.insert(big.end(), f3.begin(), f3.end());

    std::cout << "Tong so byte gui: " << big.size() << "\n";

    if (send_all(fd, big.data(), big.size())) {
        std::cout << "Da gui 3 frame dinh chum\n";
    } else {
        std::cerr << "Loi gui\n";
    }
}

void test_fragmented(int fd) {
    std::cout << "\n=== KICH BAN 2: VO GOI ===\n";
    auto frame = encode_frame("abc");
    std::cout << "Tong so byte " << frame.size() << "\n";

    for (size_t i = 0; i < frame.size(); i++) {
        if (!send_all(fd, &frame[i], 1)) {
            std::cerr << "Loi gui byte " << i << "\n";
            return;
        }
        std::cout << "Da gui byte " << i << ": 0x" << std::hex << (int)frame[i] << std::dec << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << "Da gui het frame (tung byte)\n";
}

int main(int argc, char* argv[]) {
    std::string ip = "127.0.0.1";
    int port = 8080;

    if (argc >= 3) {
        ip = argv[1];
        port = std::stoi(argv[2]);
    }

    std::cout << "Da ket noi den " << ip << ": " << port << "\n";

    int fd = connect_to_server(ip, port);
    if (fd == -1) {
        return 1;
    }
    std::cout << "Da ket noi\n";

    test_sticky(fd);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    test_fragmented(fd);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    ::close(fd);
    std::cout << "\n=== HOAN THANH ===\n";
    return 0;
}