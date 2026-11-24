#include <array>
#include <iostream>
#include <span>
#include <vector>

int sum(std::span<const int> s) {
    int total = 0;
    for (int x : s) total += x;
    return total;
}

int main() {
    std::vector<int> v = {1, 2, 3};
    std::array<int, 3> a = {4, 5, 6};
    int c[3] = {7, 8, 9};

    std::cout << sum(v) << "\n";
    std::cout << sum(a) << "\n";
    std::cout << sum(c) << "\n";

    std::cout << sum(std::span<const int>{v}.subspan(1, 2)) << "\n";
}