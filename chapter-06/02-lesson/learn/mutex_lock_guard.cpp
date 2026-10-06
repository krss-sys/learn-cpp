#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;
void tang(std::string ten) {
    for (int i = 0; i < 5; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            counter++;
            std::cout << "Tang counter len: " << counter << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    {
        std::jthread t1(tang, "Thread 1");
        std::jthread t2(tang, "Thread 2");
    }

    std::cout << "Counter cuoi cung: " << counter << "\n";
    return 0;
}