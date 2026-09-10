#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
    // 1. Tao socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cout << "Loi socket!\n";
        return 1;
    }

    // 2. Cau hinh dia chi server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Connect
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cout << "Loi connect!\n";
        close(clientSocket);
        return 1;
    }
    std::cout << "Da ket noi den server!\n";

    // 4. Gui va nhan
    const char* msg = "Hello Server!";
    send(clientSocket, msg, strlen(msg), 0);
    std::cout << "Da gui: " << msg << "\n";

    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Nhan: " << buffer << "\n";

    // 5. Dong
    close(clientSocket);

    return 0;
}