#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>
#include <thread>
using namespace std;

template <typename T>
class ThreadSafeQueue {
private:
    queue<T> q_;
    mutex mtx_;
    condition_variable cv_;
    bool closed_ = false;

public:
    void push(T value) {
        {
            lock_guard<mutex> lock(mtx_);
            q_.push(value);
        }
        cv_.notify_one();   // Báo cho consumer
    }

    optional<T> pop() {
        unique_lock<mutex> lock(mtx_);

        // Chờ đến khi có dữ liệu HOẶC queue đóng
        cv_.wait(lock, [this] { return !q_.empty() || closed_; });

        if (q_.empty()) {
            return nullopt;   // Queue đóng và rỗng
        }

        T value = q_.front();
        q_.pop();
        return value;
    }

    void close() {
        {
            lock_guard<mutex> lock(mtx_);
            closed_ = true;
        }
        cv_.notify_all();   // Đánh thức tất cả consumer
    }
};

// ==================== DEMO ====================
int main() {
    ThreadSafeQueue<int> q;

    // Producer: đẩy 5 số
    thread producer([&]() {
        for (int i = 1; i <= 5; i++) {
            q.push(i);
            cout << "Push: " << i << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        q.close();
        cout << "Producer: da dong queue" << endl;
    });

    // Consumer: lấy đến khi đóng
    thread consumer([&]() {
        while (true) {
            auto value = q.pop();
            if (!value) {
                cout << "Consumer: queue da dong, thoat" << endl;
                break;
            }
            cout << "Pop: " << *value << endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}