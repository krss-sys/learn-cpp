#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>
#include <iostream>
#include <memory>
#include <thread>

class FileDescriptor {
   private:
    int fd_;

   public:
    explicit FileDescriptor(int fd = -1) : fd_(fd) {}

    ~FileDescriptor() {
        if (fd_ >= 0) {
            ::close(fd_);
        }
    }

    FileDescriptor(const FileDescriptor&) = delete;
    FileDescriptor& operator=(const FileDescriptor&) = delete;

    FileDescriptor(FileDescriptor&& other) noexcept : fd_(other.fd_) { other.fd_ = -1; }

    FileDescriptor& operator=(FileDescriptor&& other) noexcept {
        if (this != &other) {
            if (fd_ >= 0) ::close(fd_);
            fd_ = other.fd_;
            other.fd_ = -1;
        }
        return *this;
    }

    int get() const { return fd_; }
    bool valid() const { return fd_ >= 0; }
};

bool send_all(int fd, const void* data, size_t len) {
    const char* ptr = static_cast<const char*>(data);
    size_t total_sent = 0;

    while (total_sent < len) {
        size_t n = ::send(fd, ptr + total_sent, len - total_sent, MSG_NOSIGNAL);
        if (n > 0) {
            total_sent += static_cast<size_t>(n);
        } else if (n < 0) {
            if (errno == EINTR) {
                continue;
            }
            return false;
        } else {
            return false;
        }
    }
    return true;
}

ssize_t recv_some(int fd, void* buf, size_t cap) {
    while (true) {
        ssize_t n = recv(fd, buf, cap, 0);
        if (n < 0 && errno == EINTR) {
            continue;
        }
        return n;
    }
}

void handle_echo(int clientSocket) {
    char buffer[1024];
    while (true) {
        ssize_t n = recv_some(clientSocket, buffer, sizeof(buffer));

        if (n > 0) {
            if (!send_all(clientSocket, buffer, static_cast<size_t>(n))) {
                std::cerr << "Loi gui du lieu!\n";
                break;
            }
        } else if (n == 0) {
            std::cout << "Client dong ket noi!\n";
            break;
        } else {
            std::cerr << "Recv error: " << strerror(errno) << "\n";
            break;
        }
    }
}

int main() {
    int serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Loi socket: " << strerror(errno) << "\n";
        return 1;
    }

    int opt = 1;
    ::setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (::bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Loi bind: " << strerror(errno) << "\n";
        close(serverSocket);
        return 1;
    }

    if (::listen(serverSocket, 5) == -1) {
        std::cerr << "Loi listen: " << strerror(errno) << "\n";
        close(serverSocket);
        return 1;
    }
    std::cout << "Server dang chay tren port 8080...\n";

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);

        int clientFd = ::accept(serverSocket, (sockaddr*)&clientAddr, &clientLen);
        if (clientFd == -1) {
            std::cerr << "Loi accept: " << strerror(errno) << "\n";
            continue;
        }

        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, ipStr, INET_ADDRSTRLEN);
        std::cout << "Client Ket noi: " << ipStr << ":" << ntohs(clientAddr.sin_port) << "\n";

        auto conn = std::make_shared<FileDescriptor>(clientFd);

        std::thread([conn]() { handle_echo(conn->get()); }).detach();
    }

    close(serverSocket);
    return 0;
}
