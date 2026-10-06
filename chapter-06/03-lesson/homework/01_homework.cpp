#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Worker: dang nhan di lieu...\n";
    cv.wait(lock, [] { return ready; });
    std::cout << "Worker: da nhan du lieu\n";
}

int main() {
    std::jthread t1(worker);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Main: Da gui du lieu\n";
    }
    cv.notify_one();

    t1.join();

    return 0;
}