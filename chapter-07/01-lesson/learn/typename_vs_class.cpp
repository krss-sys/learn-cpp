#include <iostream>
#include <string>

template <class T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T max2(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(5, 3) << "\n";
    std::cout << max2(5, 3) << "\n";

    std::cout << "Giong nhau\n";

    return 0;
}