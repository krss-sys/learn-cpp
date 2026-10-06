#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
using namespace std;

int main() {
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;  // dùng cho server (lắng nghe)

    int status = getaddrinfo(NULL, "8080", &hints, &result);
    if (status != 0) {
        cout << "Loi: " << gai_strerror(status) << endl;
        return 1;
    }

    int serverSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (serverSocket == -1) {
        cout << "Loi tao socket!" << endl;
        freeaddrinfo(result);
        return 1;
    }

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (bind(serverSocket, result->ai_addr, result->ai_addrlen) == -1) {
        cout << "Loi bind!" << endl;
        freeaddrinfo(result);
        close(serverSocket);
        return 1;
    }

    freeaddrinfo(result);

    if (listen(serverSocket, 5) == -1) {
        cout << "Loi listen!" << endl;
        close(serverSocket);
        return 1;
    }

    cout << "Server dang chay tren port 8080..." << endl;
    int clientSocket = accept(serverSocket, NULL, NULL);
    cout << "Client da ket noi!" << endl;

    close(clientSocket);
    close(serverSocket);
    return 0;
}