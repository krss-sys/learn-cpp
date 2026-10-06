#include <chrono>
#include <iostream>
#include <thread>

void inSo(int id) {
    for (int i = 1; i <= 3; i++) {
        std::cout << "Thread " << id << ": " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::cout << "=== 1. TAO THREAD VOI join() ===\n";
    std::thread t1(inSo, 1);
    t1.join();
    std::cout << "Thread 1 da ket thuc!\n";

    std::cout << "\n=== 2. NHIEU THREAD CHAY SONG SONG ===\n";
    std::thread t2(inSo, 2);
    std::thread t3(inSo, 3);
    t2.join();
    t3.join();
    std::cout << "Tat ca thread ket thuc!\n";

    std::cout << "\n=== 3. detach() ===\n";
    std::thread t4(inSo, 4);
    t4.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Main ket thuc\n";

    return 0;
}