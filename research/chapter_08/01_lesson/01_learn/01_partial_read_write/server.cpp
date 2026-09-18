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
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    cout << "Server dang chay..." << endl;

    int clientSocket = accept(serverSocket, NULL, NULL);
    cout << "Client da ket noi!" << endl;

    // Nhận độ dài tin nhắn trước (4 byte)
    int msgLength;
    recvAll(clientSocket, (char*)&msgLength, sizeof(msgLength));
    msgLength = ntohl(msgLength);   // chuyển về host byte order

    // Nhận tin nhắn với độ dài đã biết
    char* buffer = new char[msgLength + 1];
    recvAll(clientSocket, buffer, msgLength);
    buffer[msgLength] = '\0';

    cout << "Nhan: " << buffer << endl;

    // Gửi lại
    sendAll(clientSocket, buffer, msgLength);

    delete[] buffer;
    close(clientSocket);
    close(serverSocket);
    return 0;
}