#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Worker " << id << " dang cho...\n";
    cv.wait(lock, [] { return ready; });
    std::cout << "Worker " << id << " da duoc danh thuc\n";
}

int main() {
    std::vector<std::jthread> workers;

    // Tao 3 worker
    for (int i = 0; i < 3; i++) {
        workers.emplace_back(worker, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all();

    for (auto& t : workers) {
        t.join();
    }

    return 0;
}