#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;

queue<int> q;
mutex mtx;
condition_variable cv;
bool done = false;

void producer(int id) {
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(300 + id * 100));
        {
            lock_guard<mutex> lock(mtx);
            int value = id * 10 + i;
            q.push(value);
            cout << "Producer " << id << " them: " << value << endl;
        }
        cv.notify_one();
    }
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !q.empty() || done; });

        if (q.empty() && done) break;

        int data = q.front();
        q.pop();
        cout << "Consumer " << id << " lay: " << data << endl;
    }
}

int main() {
    vector<thread> producers;
    vector<thread> consumers;

    for (int i = 0; i < 2; i++) {
        producers.emplace_back(producer, i + 1);
    }
    for (int i = 0; i < 2; i++) {
        consumers.emplace_back(consumer, i + 1);
    }

    for (auto& t : producers) t.join();

    {
        lock_guard<mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    for (auto& t : consumers) t.join();

    return 0;
}