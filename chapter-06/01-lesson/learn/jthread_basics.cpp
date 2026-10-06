#include <chrono>
#include <iostream>
#include <thread>

void worker(std::stop_token st, int id) {
    int count = 0;
    while (!st.stop_requested()) {
        count++;
        std::cout << "\nThread " << id << " chay lan " << count << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\nThread " << id << " da dung!\n";
}

int main() {
    std::cout << "=== jthread + stop_token ===\n";
    std::jthread t1(worker, 1);
    std::jthread t2(worker, 2);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    t1.request_stop();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    t2.request_stop();

    std::cout << "\nDa yeu cau dung tat ca thread\n";

    return 0;
}