#include <endian.h>

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <optional>
#include <span>
#include <vector>

// Ghi uint16_t ra big-endian vào cuối vector
void write_u16_be(std::vector<uint8_t>& out, uint16_t v) {
    uint16_t be = htobe16(v);
    out.push_back(static_cast<uint8_t>(be >> 8));
    out.push_back(static_cast<uint8_t>(be & 0xFF));
}

// Đọc uint16_t big-endian từ span, tại vị trí pos.
// Đọc xong pos tiến 2. Không đủ byte → nullopt.
std::optional<uint16_t> read_u16_be(std::span<const uint8_t> data, size_t& pos) {
    if (pos + 2 > data.size()) return std::nullopt;
    uint16_t hi = data[pos];
    uint16_t lo = data[pos + 1];
    pos += 2;
    uint16_t be = static_cast<uint16_t>((hi << 8) | lo);
    return be16toh(be);
}

int main() {
    std::vector<uint8_t> buf;
    write_u16_be(buf, 0x1234);
    write_u16_be(buf, 0xABCD);

    std::cout << "Byte ghi ra: ";
    for (auto b : buf) std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)b << " ";
    std::cout << "\n";  // 12 34 ab cd

    size_t pos = 0;
    auto a = read_u16_be(buf, pos);
    auto b = read_u16_be(buf, pos);
    if (a) std::cout << "Đọc 1: 0x" << std::hex << *a << "\n";  // 0x1234
    if (b) std::cout << "Đọc 2: 0x" << std::hex << *b << "\n";  // 0xabcd

    // Đọc quá dữ liệu → nullopt
    auto c = read_u16_be(buf, pos);
    if (!c) std::cout << "Hết dữ liệu, không đọc được\n";  // in dòng này
}