#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

std::atomic<int> activeConnection{0};

struct ConnectionGuard {
    ConnectionGuard() {
        ++activeConnection;
        std::cout << "[+] Co client moi. Active = " << activeConnection << "\n";
    }

    ~ConnectionGuard() {
        --activeConnection;
        std::cout << "[-] Client ngat. Active = " << activeConnection << "\n";
    }

    ConnectionGuard(const ConnectionGuard&) = delete;
    ConnectionGuard& operator=(const ConnectionGuard&) = delete;
};

void handleClient(int id) {
    ConnectionGuard guard;

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    if (id % 3 == 0) {
        std::cout << "Client " << id << " thoat som (return)\n";
        return;
    }
    std::cout << "Client " << id << " da xu li xong\n";
}

int main() {
    std::cout << "=== TEST ATOMIC + RAII GUARD ===\n";

    std::thread t1(handleClient, 1);
    std::thread t2(handleClient, 2);
    std::thread t3(handleClient, 3);
    std::thread t4(handleClient, 4);
    std::thread t5(handleClient, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "=== KET THUC. Active = " << activeConnection << " ===\n";

    return 0;
}