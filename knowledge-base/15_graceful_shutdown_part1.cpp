#include <cstddef>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <csignal>
#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
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

    std::cout << "Server dang chay tren port 8080...\n";
    std::cout << "Bam Ctrl C de dung server\n";

    while (!g_stop) {
        struct pollfd pfd;
        pfd.fd = serverFd;
        pfd.events = POLL_IN;
        pfd.revents = 0;

        int ready = poll(&pfd, 1, 500);

        if (ready < 0) {
            if (errno == EINTR) {
                continue;
                break;
            }
        }

        if (ready == 0) {
            continue;
        }

        if (pfd.revents & POLL_IN) {
            int clientFd = ::accept(serverFd, NULL, NULL);
            if (clientFd >= 0) {
                std::cout << "Client ket noi!\n";
                const char* msg = "Hello";
                ::send(clientFd, msg, strlen(msg), 0);
                ::close(clientFd);
            }
        }
    }
    std::cout << "\nServer dang tat...\n";
    ::close(serverFd);
    std::cout << "Da tat sach se\n";
    return 0;
}