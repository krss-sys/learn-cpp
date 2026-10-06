#include <chrono>
#include <iostream>
#include <thread>

void worker(std::stop_token st, int id) {
    int count = 0;
    while (!st.stop_requested()) {
        count++;
        std::cout << "worker " << id << " da chay: " << count << " lan\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "worker " << id << " da dung\n";
}

int main() {
    std::jthread t1(worker, 1);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    t1.request_stop();

    return 0;
}