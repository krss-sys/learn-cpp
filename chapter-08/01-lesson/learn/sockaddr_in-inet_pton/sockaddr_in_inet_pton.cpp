#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

int main() {
    std::cout << "=== SO SANH INADDR_ANY VA INET_PTON ===\n";

    // 1. INADDR_ANY (server)
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    std::cout << "Server: INADDR_ANY (lang nghe tat ca IP)\n";

    // 2. inet_pton (client)
    sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr) == 1) {
        std::cout << "Client: inet_pton thanh cong (127.0.0.1)\n";
    } else {
        std::cout << "Client: inet_pton that bai\n";
    }

    // 3. Chuyen nguoc binary sang chuoi (inet_ntop)
    char ipStr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, ipStr, INET_ADDRSTRLEN);
    std::cout << "IP cua client: " << ipStr << "\n";

    return 0;
}