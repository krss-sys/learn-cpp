#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

void inSo(int x, const std::string& msg) {
    for (int i = 1; i <= 3; i++) {
        std::cout << msg << x << "- lan " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void tangSo(int& x) {
    x++;
    std::cout << "Tang x len: " << x << "\n";
}

int main() {
    std::cout << "=== 1. TRUYEN THAM SO BINH THUONG ===\n";
    std::thread t1(inSo, 10, "Gia tri: ");
    t1.join();

    std::cout << "\n=== 2. TRUYEN THAM CHIEU (ref) ===\n";
    int a = 5;
    std::cout << "a ban dau: " << a << "\n";
    std::thread t2(tangSo, std::ref(a));
    t2.join();
    std::cout << "a sau tang: " << a << "\n";

    std::cout << "\n=== 3. sleep_for trong thread ===\n";
    std::thread t3([]() {
        for (int i = 1; i <= 5; i++) {
            std::cout << "Thread 3: " << i << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    });
    t3.join();

    return 0;
}