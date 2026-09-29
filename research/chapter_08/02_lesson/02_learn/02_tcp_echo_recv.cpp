#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>
#include <iostream>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Loi socket: " << strerror(errno) << std::endl;
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Loi bind: " << strerror(errno) << std::endl;
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Loi listen: " << strerror(errno) << std::endl;
        close(serverSocket);
        return 1;
    }
    std::cout << "Server dang chay tren port 8080...\n";

    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == -1) {
        std::cerr << "Loi accept: " << strerror(errno) << "\n";
        close(serverSocket);
        return 1;
    }
    std::cout << "Client da ket noi!\n";

    char buffer[1024];

    while (true) {
        ssize_t n = ::recv(clientSocket, buffer, sizeof(buffer), 0);
        if (n > 0) {
            ::send(clientSocket, buffer, n, 0);
        } else if (n == 0) {
            std::cout << "peer closed\n";
            break;
        } else {
            std::cerr << "recv error: " << strerror(errno) << "\n";
            break;
        }
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}