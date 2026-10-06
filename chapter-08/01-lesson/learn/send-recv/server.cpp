#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    std::cout << "Server dang chay tren port 8080...\n";

    int clientSocket = accept(serverSocket, NULL, NULL);
    std::cout << "Client da ket noi!\n";

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Client gui: " << buffer << "\n";

    const char* reply = "Hello Client!";
    send(clientSocket, reply, strlen(reply), 0);

    close(clientSocket);
    close(serverSocket);
    return 0;
}