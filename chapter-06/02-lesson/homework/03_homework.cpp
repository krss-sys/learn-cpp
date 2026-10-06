#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::atomic<int> counter = 0;

void tang() {
    for (int i = 0; i < 10000; i++) {
        counter++;
    }
}

int main() {
    // test git diff
    std::cout << "\n=== ATOMIC ===\n";
    {
        std::jthread t1(tang);
        std::jthread t2(tang);
    }
    std::cout << "  Atomic counter: " << counter << "\n";

    std::cout << "\n=== DEADLOCK ===\n";
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

    std::jthread t3(task1);
    std::jthread t4(task2);
    t3.join();
    t4.join();

    return 0;
}