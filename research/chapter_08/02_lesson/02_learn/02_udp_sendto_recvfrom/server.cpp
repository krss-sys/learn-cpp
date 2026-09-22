#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(NULL, "8080", &hints, &result);
    if (status != 0) {
        std::cout << "LOI: " << gai_strerror(status) << "\n";
    }

    int serverSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (serverSocket == -1) {
        std::cout << "Loi tao socket\n";
        freeaddrinfo(result);
        return 1;
    }

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(serverSocket, result->ai_addr, result->ai_addrlen) == -1) {
        std::cout << "Loi bind!\n";
        freeaddrinfo(result);
        close(serverSocket);
        return 1;
    }
    std::cout << "UDP server dang chay tren port 8080...\n";

    char buffer[1024] = {0};
    sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    int bytes =
        recvfrom(serverSocket, buffer, sizeof(buffer), 0, (sockaddr*)&clientAddr, &clientLen);
    std::cout << "Nhan tu " << inet_ntoa(clientAddr.sin_addr) << ": " << ntohs(clientAddr.sin_port)
              << "\n";
    std::cout << "Noi dung: " << buffer << "\n";

    const char* reply = "Hello from UDP server!";
    sendto(serverSocket, reply, strlen(reply), 0, (sockaddr*)&clientAddr, clientLen);

    close(serverSocket);

    return 0;
}