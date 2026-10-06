#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::atomic<int> counterAtomic = 0;
int counterMutex = 0;
std::mutex mtx;

void tangAtomic() {
    for (int i = 0; i < 10000; i++) {
        counterAtomic++;
    }
}

void tangMutex() {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        counterMutex++;
    }
}

int main() {
    std::cout << "=== ATOMIC ===\n";
    std::jthread t1(tangAtomic);
    std::jthread t2(tangAtomic);
    std::cout << "  Atomic counter: " << counterAtomic << "\n";

    std::cout << "\n=== MUTEX ===\n";
    std::jthread t3(tangMutex);
    std::jthread t4(tangMutex);
    std::cout << "  Mutex counter: " << counterMutex << "\n";

    std::cout << "\n=== KHONG DEADLOCK ===\n";
    std::mutex mtxA, mtxB;

    auto task1 = [&]() {
        std::scoped_lock lock(mtxA, mtxB);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "  task 1 hoan thanh\n";
    };

    auto task2 = [&]() {
        std::scoped_lock lock(mtxB, mtxA);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "  task 2 hoan thanh\n";
    };

    std::jthread t5(task1);
    std::jthread t6(task2);

    return 0;
}