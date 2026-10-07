#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Cach dung: " << argv[0] << " <IP> <Port> <Message>\n";
        return 1;
    }

    std::string ip = argv[1];
    int port = std::stoi(argv[2]);
    std::string message = argv[3];

    std::cout << "IP: " << ip << "\n";
    std::cout << "Port: " << port << "\n";
    std::cout << "Message: " << message << "\n";

    return 0;
}