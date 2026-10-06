#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;

void unlockSom() {
    for (int i = 0; i < 3; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        counter++;
        std::cout << "Unlock som: " << counter << "\n";
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void deferLock() {
    for (int i = 0; i < 3; i++) {
        std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        lock.lock();
        counter++;
        std::cout << "DeferLock: " << counter << "\n";
    } 
}

int main() {
    {
        {std::cout << "=== UNLOCK SOM ===\n";
        std::jthread t1(unlockSom);}

        {std::cout << "\n=== DEFERLOCK ===\n";
        std::jthread t2(deferLock);}
    }

    std::cout << "\n    Counter cuoi cung: " << counter << "\n";

    return 0;
}