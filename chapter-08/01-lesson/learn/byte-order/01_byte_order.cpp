#include <arpa/inet.h>

#include <iostream>
using namespace std;

int main() {
    unsigned short port = 8080;
    unsigned long ip = 0x7F000001;  // 127.0.0.1

    cout << "=== TRUOC KHI CHUYEN ===" << endl;
    cout << "Port: " << port << endl;
    cout << "IP: " << ip << endl;

    // Chuyển sang network byte order
    unsigned short portNetwork = htons(port);
    unsigned long ipNetwork = htonl(ip);

    cout << "\n=== SAU KHI CHUYEN (network byte order) ===" << endl;
    cout << "Port network: " << portNetwork << endl;
    cout << "IP network: " << ipNetwork << endl;

    // Chuyển ngược lại
    unsigned short portHost = ntohs(portNetwork);
    unsigned long ipHost = ntohl(ipNetwork);

    cout << "\n=== CHUYEN NGUOC VE HOST ===" << endl;
    cout << "Port host: " << portHost << endl;
    cout << "IP host: " << ipHost << endl;

    return 0;
}