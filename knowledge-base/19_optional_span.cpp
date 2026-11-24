#include <cstddef>
#include <cstdint>
#include <iostream>
#include <optional>
#include <span>
#include <vector>

std::optional<size_t> find_byte(std::span<const uint8_t> data, uint8_t target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) return i;
    }
    return std::nullopt;
}

int main() {
    std::vector<uint8_t> buf = {0x10, 0x20, 0x30, 0x40};

    auto pos = find_byte(buf, 0x30);
    if (pos.has_value())
        std::cout << "Tim thay tai vi tri " << *pos << "\n";
    else
        std::cout << "Khong tim thay\n";

    auto miss = find_byte(buf, 0xFF);
    if (miss.has_value())
        std::cout << "Tim thay tai vi tri " << *miss << "\n";
    else
        std::cout << "Khong tim thay\n";

    auto sub = find_byte(std::span<const uint8_t>{buf}.subspan(0, 2), 0x30);
    if (sub)
        std::cout << "Tim thay tai vi tri " << *sub << "\n";
    else
        std::cout << "Khong tim thay\n";

    return 0;
}