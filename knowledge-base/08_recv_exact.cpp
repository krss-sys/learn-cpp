#include <sys/socket.h>
#include <unistd.h>

#include <cerrno>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
using namespace std;

bool recv_exact(int fd, void* buf, size_t n) {
    char* ptr = static_cast<char*>(buf);
    size_t n_left = n;

    while (n_left > 0) {
        ssize_t received = ::recv(fd, ptr, n_left, 0);

        if (received > 0) {
            ptr += received;
            n_left -= received;
        } else if (received == 0) {
            return false;
        } else {
            if (errno == EINTR) continue;
            return false;
        }
    }
    return true;
}

int main() {
    cout << "=== TEST recv_exact ===\n";

    // 1. Tạo cặp socket nối với nhau
    int sv[2];
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1) {
        cerr << "Loi socketpair: " << strerror(errno) << endl;
        return 1;
    }

    // 2. Thread ghi (giả lập client gửi 4 byte, nhưng gửi từng phần)
    thread sender([&]() {
        // Gửi 2 byte đầu
        ::write(sv[0], "AB", 2);
        cout << "[Sender] Da gui AB\n";
        this_thread::sleep_for(chrono::milliseconds(200));

        // Gửi 2 byte sau
        ::write(sv[0], "CD", 2);
        cout << "[Sender] Da gui CD\n";
    });

    // 3. Thread chính đọc 4 byte (recv_exact sẽ block tới khi đủ)
    char buf[4];
    bool ok = recv_exact(sv[1], buf, 4);

    if (ok) {
        cout << "[Main] Doc duoc 4 byte: ";
        for (int i = 0; i < 4; i++) cout << buf[i];
        cout << endl;
        cout << "[PASS]\n";
    } else {
        cout << "[FAIL] recv_exact that bai\n";
    }

    sender.join();
    ::close(sv[0]);
    ::close(sv[1]);

    return 0;
}