#include <optional>
#include <string>
#include <iostream>

std::optional<int> parse_age(const std::string& s) {
    if (s.empty()) return std::nullopt;      // chuỗi rỗng → không có tuổi
    int age = 0;
    for (char c : s) {
        if (c < '0' || c > '9') return std::nullopt;  // có ký tự không phải số → nullopt
        age = age * 10 + (c - '0');
    }
    return age;  // parse thành công → trả tuổi
}

int main() {
    auto a = parse_age("25");
    if (a) std::cout << "Tuổi: " << *a << "\n";   // in 25
    else   std::cout << "Không parse được\n";

    auto b = parse_age("abc");
    if (b) std::cout << "Tuổi: " << *b << "\n";
    else   std::cout << "Không parse được\n";     // in "Không parse được"

    auto c = parse_age("");
    if (c) std::cout << "Tuổi: " << *c << "\n";
    else   std::cout << "Không parse được\n";     // in "Không parse được"
}