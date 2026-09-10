#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // 1. Tạo socket cho Server (IPv4, TCP)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Thiết lập địa chỉ (Chạy cổng 8080)
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // Chấp nhận kết nối từ mọi IP
    address.sin_port = htons(8080);        // Cổng 8080

    // Gán địa chỉ vào socket
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    // 3. Chuyển socket sang chế độ chờ kết nối (queue chứa tối đa 3 client)
    listen(server_fd, 3);
    cout << "[SERVER] Dang cho Client ket noi o port 8080..." << endl;

    // 4. Chờ và chấp nhận kết nối từ Client (Chương trình dừng ở đây cho tới khi có Client gọi vào)
    int addrlen = sizeof(address);
    int client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    cout << "[SERVER] Check-in: Da co Client ket noi thanh cong!" << endl;

    // 5. Nhận dữ liệu từ Client
    char buffer[1024] = {0};
    recv(client_socket, buffer, sizeof(buffer), 0);
    cout << "[SERVER] Nhan tu Client: " << buffer << endl;

    // 6. Gửi phản hồi lại cho Client
    string message = "Alo Client, tao la Server day!";
    send(client_socket, message.c_str(), message.length(), 0);

    // 7. Đóng socket
    close(client_socket);
    close(server_fd);
    return 0;
}