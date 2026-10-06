#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
    // 1. Tao socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cout << "Loi socket!\n";
        return 1;
    }

    // 2. Cau hinh dia chi
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cout << "Loi bind!\n";
        close(serverSocket);
        return 1;
    }

    // 4. Listen
    if (listen(serverSocket, 5) == -1) {
        std::cout << "Loi listen!\n";
        close(serverSocket);
        return 1;
    }
    std::cout << "Server dang chay tren port 8080...\n";

    // 5. Accept
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == -1) {
        std::cout << "Loi accept!\n";
        close(serverSocket);
        return 1;
    }
    std::cout << "Client da ket noi!\n";

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Nhan: " << buffer << "\n";
    send(clientSocket, buffer, strlen(buffer), 0);

    // 7. Dong
    close(clientSocket);
    close(serverSocket);

    return 0;
}