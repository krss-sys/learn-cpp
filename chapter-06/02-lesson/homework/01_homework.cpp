#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int counter = 0;
std::mutex mtx;
void tang(std::string ten) {
    for (int i = 0; i < 5; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            counter++;
            std::cout << ten << ": " << "Counter = " << counter << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    {
        std::jthread t1(tang, "Thread 1");
        std::jthread t2(tang, "Thread 2");
        std::jthread t3(tang, "Thread 3");
    }

    std::cout<< "Counter hien tai: " << counter << "\n";

    return 0;
}