#include <deque>
#include <vector>
#include <cstdint>
#include <utility>
#include <optional>
#include <iostream>

struct ReadResult {
    uint64_t first_offset;
    std::vector<std::vector<uint8_t>> messages;
};

class TopicLog {
public:
    // Thêm message vào cuối, trả offset của nó
    uint64_t append(std::vector<uint8_t> msg) {
        uint64_t offset = base_offset_ + log_.size();
        log_.push_back(std::move(msg));  // chuyển ruột, không copy
        return offset;
    }

    // Đọc từ offset `from`, tối đa `max_msgs` message
    std::optional<ReadResult> read(uint64_t from, size_t max_msgs) {
        uint64_t next = base_offset_ + log_.size();
        if (from >= next) return ReadResult{from, {}};  // rỗng
        if (from < base_offset_) from = base_offset_;   // kẹp về base

        size_t start = static_cast<size_t>(from - base_offset_);
        size_t count = std::min(max_msgs, log_.size() - start);

        ReadResult result;
        result.first_offset = from;
        result.messages.reserve(count);
        for (size_t i = 0; i < count; ++i) {
            result.messages.push_back(log_[start + i]);  // copy ra ngoài (message phải sống sau read)
        }
        return result;
    }

    uint64_t next_offset() const { return base_offset_ + log_.size(); }
    uint64_t base_offset() const { return base_offset_; }

private:
    std::deque<std::vector<uint8_t>> log_;
    uint64_t base_offset_ = 0;
};

int main() {
    TopicLog log;

    std::vector<uint8_t> m1 = {1, 2, 3};
    uint64_t o1 = log.append(std::move(m1));  // chuyển m1, không copy
    std::cout << "append offset = " << o1 << "\n";  // 0

    log.append({4, 5});  // truyền tạm, tự move
    std::cout << "next = " << log.next_offset() << "\n";  // 2

    auto r = log.read(0, 10);
    if (r) {
        std::cout << "read from " << r->first_offset << ", count = " << r->messages.size() << "\n";  // 0, 2
    }

    auto empty = log.read(5, 10);
    if (empty) std::cout << "read from 5: count = " << empty->messages.size() << "\n";  // 0
}