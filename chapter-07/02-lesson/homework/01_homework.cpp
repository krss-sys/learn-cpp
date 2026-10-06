#include <iostream>

int main() {
    std::cout << "=== 1. LAMBDA KHONG THAM SO ===\n";
    auto chao = []() { std::cout << "  Hello from lambda\n"; };
    chao();

    std::cout << "\n=== 2. LAMBDA CO THAM SO ===\n";
    auto tich = [](int a, int b) { return a * b; };
    std::cout << "  5 * 3 = " << tich(5, 3) << "\n";

    std::cout << "\n=== 3. LAMBDA CAPTURE BY VALUE ===\n";
    int a = 10;
    auto lambda1 = [=]() { std::cout << "  a = " << a << "\n"; };
    a = 20;
    lambda1();

    std::cout << "\n=== 4. LAMBDA CAPTURE BT REFERENCE ===\n";
    int b = 10;
    auto lambda2 = [&]() { std::cout << "  b = " << b << "\n"; };
    b = 20;
    lambda2();

    std::cout << "\n=== 5. LAMBDA CAPTURE CU THE ===\n";
    int x = 5, y = 10;
    auto lambda3 = [x, &y]() {
        y++;
        std::cout << "  x = " << x << "; y = " << y << "\n";
    };
    lambda3();

    return 0;
}