#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

bool sendAll(int socket, const char* data, int length) {
    int totalSent = 0;
    while (totalSent < length) {
        int sent = send(socket, data + totalSent, length - totalSent, 0);
        if (sent <= 0) return false;
        totalSent += sent;
    }
    return true;
}

bool recvAll(int socket, char* buffer, int length) {
    int totalReceived = 0;
    while (totalReceived < length) {
        int received = recv(socket, buffer + totalReceived, length - totalReceived, 0);
        if (received <= 0) return false;
        totalReceived += received;
    }
    return true;
}

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    cout << "Da ket noi!" << endl;

    const char* msg = "Hello Server!";
    int msgLength = strlen(msg);

    // Gửi độ dài trước (đã chuyển byte order)
    int msgLengthNetwork = htonl(msgLength);
    sendAll(clientSocket, (char*)&msgLengthNetwork, sizeof(msgLengthNetwork));

    // Gửi tin nhắn
    sendAll(clientSocket, msg, msgLength);

    // Nhận lại
    char buffer[1024] = {0};
    recvAll(clientSocket, buffer, msgLength);
    cout << "Nhan: " << buffer << endl;

    close(clientSocket);
    return 0;
}