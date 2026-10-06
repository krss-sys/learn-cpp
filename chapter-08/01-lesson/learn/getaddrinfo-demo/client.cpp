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

    int status = getaddrinfo("127.0.0.1", "8080", &hints, &result);
    if (status != 0) {
        cout << "Loi: " << gai_strerror(status) << endl;
        return 1;
    }

    int clientSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (clientSocket == -1) {
        cout << "Loi tao socket!" << endl;
        freeaddrinfo(result);
        return 1;
    }

    if (connect(clientSocket, result->ai_addr, result->ai_addrlen) == -1) {
        cout << "Loi ket noi!" << endl;
        freeaddrinfo(result);
        close(clientSocket);
        return 1;
    }

    cout << "Da ket noi den server!" << endl;

    freeaddrinfo(result);
    close(clientSocket);
    return 0;
}