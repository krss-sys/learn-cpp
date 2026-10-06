#include <iostream>
#include <string>

// 1. Ham max tong quat
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

// 2. Ham swap tong quat
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 3. Ham binh phuong
template <typename T>
T binhPhuong(T x) {
    return x * x;
}

// 4. Ham voi 2 kieu tham so khac nhau
template <typename T1, typename T2>
void in(T1 a, T2 b) {
    std::cout << a << " - " << b << "\n";
}

int main() {
    std::cout << "===Max ===\n";
    std::cout << myMax(10, 20) << "\n";
    std::cout << myMax(3.14, 2.17) << "\n";
    std::cout << myMax(std::string("abc"), std::string("adb")) << "\n";

    std::cout << "\n=== Swap ===\n";
    int a = 5, b = 10;
    std::cout << "Truoc: a = " << a << "; b = " << b << "\n";
    swap(a, b);
    std::cout << "Sau: a = " << a << "; b = " << b << "\n";

    std::cout << "\n=== Ham binh phuong ===\n";
    std::cout << binhPhuong(5) << "\n";
    std::cout << binhPhuong(3.5) << "\n";

    std::cout << "\n=== 2 kieu khac nhau ===\n";
    in(5, 3.14);
    in("Hello", 100);

    return 0;
}
