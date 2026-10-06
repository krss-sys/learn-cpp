#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

void binhPhuong(int id, const std::string& prefix) {
    for (int i = 1; i <= 5; i++) {
        std::cout << "\n[Thread " << id << "]" << prefix << i << "^2 = " << i * i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void tongCongDon(int& tong) {
    for (int i = 1; i <= 5; i++) {
        tong++;
        std::cout << "Thread 2: Tong = " << tong << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::cout << "=== THREAD 1 ===\n";
    std::thread t1(binhPhuong, 1, " prefix ");

    std::cout << "\n=== THREAD 2 ===\n";
    int tong = 0;
    std::thread t2(tongCongDon, std::ref(tong));
    t1.join();
    t2.join();

    std::cout << "Tong cuoi cung = " << tong << "\n";

    return 0;
}