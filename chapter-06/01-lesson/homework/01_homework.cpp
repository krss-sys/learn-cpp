#include <chrono>
#include <iostream>
#include <thread>

void demSo(int n) {
    for (int i = 1; i <= 5; i++) {
        std::cout << "Thread " << n << ": " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::cout << "=== THREAD CHAY SONG SONG ===\n";
    std::thread t1(demSo, 1);
    std::thread t2(demSo, 2);
    std::thread t3(demSo, 3);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Tat ca thread chay xong\n";

    return 0;
}