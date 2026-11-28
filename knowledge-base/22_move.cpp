#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

void append(std::vector<uint8_t> msg, std::vector<std::vector<uint8_t>>& log) {
    log.push_back(std::move(msg));
}

int main() {
    std::vector<std::vector<uint8_t>> log;

    std::vector<uint8_t> a = {1, 2, 3};
    append(std::move(a), log);

    std::cout << log[0].size() << "\n";

    return 0;
}