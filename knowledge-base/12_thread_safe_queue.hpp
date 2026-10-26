#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

namespace aether {

template <typename T>
class ThreadSafeQueue {
private:
    std::queue<T> q_;
    std::mutex mtx_;
    std::condition_variable cv_;
    bool closed_ = false;

public:
    void push(T value) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            q_.push(std::move(value));
        }
        cv_.notify_one();
    }

    std::optional<T> pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return !q_.empty() || closed_; });

        if (q_.empty()) return std::nullopt;

        T value = std::move(q_.front());
        q_.pop();
        return value;
    }

    void close() {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            closed_ = true;
        }
        cv_.notify_all();
    }
};

} // namespace aether