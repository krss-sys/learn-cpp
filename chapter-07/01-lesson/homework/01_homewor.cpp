#include <iostream>
#include <string>

template <typename T1, typename T2>
auto timMin(const T1& a, const T2& b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
auto tinhTong(const T1& a, const T2& b) {
    return a + b;
}

template <typename T1, typename T2>
std::string soSanh(const T1& a, const T2& b) {
    return (a == b) ? "Giong nhau" : "Khac nhau";
}

int main() {
    std::cout << "=== TIM MIN ===\n";
    std::cout << timMin(4, 3.67) << "\n";
    std::cout << timMin(300, 7.35) << "\n";

    std::cout << "\n=== TINH TONG ===\n";
    std::cout << tinhTong(3, 6.09);

    std::cout << "\n=== SO SANH ===\n";
    std::cout << soSanh(3, 5.6) << "\n";
    std::cout << soSanh(30, 30) << "\n";

    return 0;
}