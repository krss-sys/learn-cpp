#include <iostream>
#include <string>

void printAll() { std::cout << "(empty)\n"; }

template <typename T, typename... Args>
void printAll(T first, Args... rest) {
    std::cout << first << "\n";
    printAll(rest...);
}

int sum() { return 0; }

template <typename T, typename... Args>
T sum(T first, Args... rest) {
    return first + sum(rest...);
}

template <typename... Args>
void demSoLuong(Args... args) {
    std::cout << "So luong tham so: " << sizeof...(args) << "\n";
}

int main() {
    std::cout << "=== 1. printAll ===\n";
    printAll();
    printAll(10);
    printAll(1, 2.5, "Hello", 20);

    std::cout << "\n=== 2. sum ===\n";
    std::cout << "sum(1, 2, 3, 4, 5) = " << sum(1, 2, 3, 4, 5) << "\n";
    std::cout << "sum(10, 20, 30) = " << sum(10, 20, 30) << "\n";

    std::cout << "\n=== 3. sizeof... ===\n";
    demSoLuong();
    demSoLuong(10);
    demSoLuong(1, 2.5, "Hello", 20);

    return 0;
}