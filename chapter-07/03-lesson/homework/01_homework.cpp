#include <iostream>

template <typename T>
T maxAll(T val) {
    return val;
}

template <typename T, typename... Args>
T maxAll(T first, Args... rest) {
    return std::max(first, maxAll(rest...));
}

int main() {
    std::cout << maxAll(10, 11, 4, 5, 34, 7) << "\n";

    return 0;
}