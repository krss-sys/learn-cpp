#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

int main() {
    // 1. Tạo socket UDP
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == -1) {
        cout << "Loi tao socket!" << endl;
        return 1;
    }

    // 2. Cấu hình địa chỉ server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    // 3. Gửi dữ liệu (KHÔNG cần connect)
    const char* msg = "Hello UDP Server!";
    sendto(clientSocket, msg, strlen(msg), 0,
           (sockaddr*)&serverAddr, sizeof(serverAddr));
    cout << "Da gui: " << msg << endl;

    // 4. Nhận phản hồi
    char buffer[1024] = {0};
    sockaddr_in fromAddr;
    socklen_t fromLen = sizeof(fromAddr);

    int bytes = recvfrom(clientSocket, buffer, sizeof(buffer), 0,
                         (sockaddr*)&fromAddr, &fromLen);
    cout << "Nhan: " << buffer << endl;

    // 5. Đóng
    close(clientSocket);
    return 0;
}