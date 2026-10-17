#include <iostream>
#include <vector>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

std::vector<uint8_t> encode_frame(const std::string& msg) {
    uint32_t len = msg.size();
    uint32_t lenN = htonl(len);

    std::vector<uint8_t> frame;
    const uint8_t* lenBytes = reinterpret_cast<const uint8_t*>(&lenN);
    for (int i = 0; i < 4; i++) frame.push_back(lenBytes[i]);
    for (char c : msg) frame.push_back(static_cast<uint8_t>(c));
    return frame;
}

bool send_all(int fd, const void* data, size_t len) {
    const char* ptr = static_cast<const char*>(data);
    size_t total = 0;

    while (total < len) {
        ssize_t n = ::send(fd, ptr + total, len - total, MSG_NOSIGNAL);
        if (n > 0) total += static_cast<size_t>(n);
        else if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        }
        else return false;
    }
    return true;
}

int connect_to_server(const std::string& ip, int port) {
    int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        std::cerr << "Loi socket: " << strerror(errno) << std::endl;
        return -1;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    if (::connect(fd, (sockaddr*)&addr, sizeof(addr)) == -1) {
        std::cerr << "Loi connect: " << strerror(errno) << std::endl;
        ::close(fd);
        return -1;
    }
    return fd;
}

bool test_sticky(const std::string& ip, int port) {
    std::cout << "\n=== KICH BAN 1: DINH GOI ===\n";

    int fd = connect_to_server(ip, port);
    if (fd == -1) return false;

    auto f1 = encode_frame("Hello A");
    auto f2 = encode_frame("System");
    auto f3 = encode_frame("C++20");

    std::vector<uint8_t> big;
    big.insert(big.end(), f1.begin(), f1.end());
    big.insert(big.end(), f2.begin(), f2.end());
    big.insert(big.end(), f3.begin(), f3.end());

    bool ok = send_all(fd, big.data(), big.size());
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    ::close(fd);

    if (ok) {
        std::cout << "[PASS] Da gui 3 frame dinh chum.\n";
        return true;
    }
    std::cout << "[FAIL] Loi gui.\n";
    return false;
}

bool test_fragmented(const std::string& ip, int port) {
    std::cout << "\n=== KICH BAN 2: VO GOI ===\n";

    int fd = connect_to_server(ip, port);
    if (fd == -1) return false;

    auto frame = encode_frame("abc");
    std::cout << "Tong so byte: " << frame.size() << std::endl;

    for (size_t i = 0; i < frame.size(); i++) {
        if (!send_all(fd, &frame[i], 1)) {
            std::cerr << "[FAIL] Loi gui byte " << i << std::endl;
            ::close(fd);
            return false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    ::close(fd);

    std::cout << "[PASS] Da gui tung byte.\n";
    return true;
}

bool test_malicious(const std::string& ip, int port) {
    std::cout << "\n=== KICH BAN 3: MALICIOUS HEADER ===\n";

    int fd = connect_to_server(ip, port);
    if (fd == -1) return false;

    std::vector<uint8_t> badFrame = {0xFF, 0xFF, 0xFF, 0xFF, 'a', 'b'};
    send_all(fd, badFrame.data(), badFrame.size());
    std::cout << "Da gui frame doc hai (len = 0xFFFFFFFF)\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    char buf[16];
    ssize_t n = recv(fd, buf, sizeof(buf), 0);
    ::close(fd);

    if (n == 0) {
        std::cout << "[PASS] Server da dong ket noi (phong thu oke)\n";
        return true;
    }
    if (n < 0) {
        std::cout << "[PASS] Server da dong ket noi (recv loi)\n";
        return true;
    }
    std::cout << "[FAIL] Server van con mo (n = " << n << ").\n";
    return false;
}

int main(int argc, char* argv[]) {
    std::string ip = "127.0.0.1";
    int port = 8080;

    if (argc >= 3) {
        ip = argv[1];
        port = std::stoi(argv[2]);
    }

    std::cout << "=== FRAME TORTURE TEST ===\n";
    std::cout << "Target: " << ip << ":" << port << std::endl;

    bool allPassed = true;

    if (!test_sticky(ip, port)) allPassed = false;
    if (!test_fragmented(ip, port)) allPassed = false;
    if (!test_malicious(ip, port)) allPassed = false;

    std::cout << "\n=== KET QUA ===\n";
    if (allPassed) {
        std::cout << "[ALL PASS] Tat ca test deu pass\n";
        return EXIT_SUCCESS;
    }
    std::cout << "[SOME ALL] Co test that bai\n";
    return EXIT_FAILURE;
}