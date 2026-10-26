#include "11_thread_pool.hpp"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    aether::ThreadPool pool(4);

    for (int i = 1; i <= 10; ++i) {
        pool.submit([i]() {
            cout << "Task " << i << " chay tren thread "
                 << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        });
    }

    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}