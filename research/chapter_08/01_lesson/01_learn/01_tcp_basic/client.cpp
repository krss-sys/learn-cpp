#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // 1. Tạo socket cho Client
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Cấu hình địa chỉ Server cần kết nối (IP 127.0.0.1 - localhost, Port 8080)
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Kết nối tới Server
    cout << "[CLIENT] Dang ket noi toi Server..." << endl;
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    cout << "[CLIENT] Da ket noi thanh cong!" << endl;

    // 4. Gửi tin nhắn cho Server
    string message = "Chao Server, tao la Client krss!";
    send(sock, message.c_str(), message.length(), 0);

    // 5. Nhận phản hồi từ Server
    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);
    cout << "[CLIENT] Server phan hoi: " << buffer << endl;

    // 6. Đóng socket
    close(sock);
    return 0;
}