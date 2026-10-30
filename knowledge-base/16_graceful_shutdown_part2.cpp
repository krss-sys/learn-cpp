#include <cstddef>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <csignal>
#include <asm-generic/socket.h>
#include <poll.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

volatile sig_atomic_t g_stop = 0;

void handle_signal(int sig) {
    g_stop = 1;
}

void setup_signals() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
}

void handle_client(int clientFd) {
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(clientFd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    char buf[1024];

    while (!g_stop) {
        ssize_t n = ::recv(clientFd, buf, sizeof(buf), 0);

        if (n > 0) {
            ::send(clientFd, buf, n, 0);
        } else if (n == 0) {
            std::cout << "Client dong ket noi\n";
            break;
        } else {
            if (g_stop) break;
            if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
                continue;
            }
            std::cerr << "Recv error: " << strerror(errno) << "\n";
            break;
        }
    }
    ::close(clientFd);
    std::cout << "\nDa dong client\n";
}

int main() {
    setup_signals();

    int serverFd = ::socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    ::setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    ::bind(serverFd, (sockaddr*)&addr, sizeof(addr));
    ::listen(serverFd, 5);

    std::cout << "Server dang chay tren port 8080..." << "\n";
    std::cout << "Bam Ctrl+C de dung." << "\n"; 
    
    while (!g_stop){
        struct pollfd pfd;
        pfd.fd = serverFd;
        pfd.events = POLLIN;
        pfd.revents = 0;

        int ready = poll(&pfd, 1, 500);

        if (ready < 0) {
            if (errno == EINTR) continue;
            break;
        }

        if (ready == 0) continue;

        if (pfd.revents & POLLIN) {
            int clientFd = ::accept(serverFd, NULL, NULL);
            if (clientFd >= 0) {
                std::cout << "Client ket noi\n";
                handle_client(clientFd);
            }
        }
    }

    std::cout << "\nServer dang tat...\n";
    ::close(serverFd);
    std::cout << "Da tat sach se\n";

    return 0;
}
