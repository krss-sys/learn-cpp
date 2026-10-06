#include <iostream>

int main() {
    std::cout << "=== 1. LAMBDA CO BAN ===\n";
    auto chao = []() { std::cout << "Xin chao!\n"; };
    chao();

    auto cong = [](int a, int b) { return a + b; };
    std::cout << "5 + 3 = " << cong(5, 3);

    std::cout << "\n=== 2. CAPTURE BY VALUE [=] ===\n";
    int a = 10;
    auto lambda1 = [=]() { std::cout << "a = " << a << "\n"; };
    a = 20;
    lambda1();

    std::cout << "\n=== 3. CAPTURE BY REFERENCE [&] ===\n";
    int b = 10;
    auto lambda2 = [&]() { std::cout << "b = " << b << "\n"; };
    b = 20;
    lambda2();

    std::cout << "\n=== 4. CAPYURE CU THE [x, &y] ===\n";
    int x = 5, y = 10;
    auto lambda3 = [x, &y]() {
        y++;
        std::cout << "x = " << x << "; y = " << y << "\n";
    };
    lambda3();
    std::cout << "  Sau lambda: y = " << y << "\n";

    std::cout << "\n=== 5. LAMBDA VOI RETURN TYPE ===\n";
    auto chia = [](double a, double b) -> double {
        if (b == 0) {
            return 0;
        }
        return a / b;
    };
    std::cout << "10 / 3 = " << chia(10, 3) << "\n";

    return 0;
}