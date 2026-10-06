#include <iostream>
#include <string>

template <typename T>
void in(T val) {
    std::cout << "[GENERIC]: " << val << "\n";
}

template <>
void in<std::string>(std::string val) {
    std::cout << "[SPECIAL] string: " << val << "\n";
}

template <>
void in<int>(int val) {
    std::cout << "[SPECIAL] int: " << val << "\n";
}

template <typename T>
class Box {
   private:
    T value;

   public:
    Box(T val) : value(val) {}

    void print() const { std::cout << "[GENERIC] Box: " << value << "\n"; }
};

template <>
class Box<bool> {
   private:
    bool value;

   public:
    Box(bool val) : value(val) {}

    void print() const { std::cout << "[SPECIAL] Box<bool>: " << (value ? "true\n" : "false\n"); }
};

int main() {
    std::cout << "=== FUNCTION TEMPLATE SPECIALIZATION ===\n";
    in(10);
    in(3.14);
    in(std::string("Hello"));

    std::cout << "\n=== CLASS TEMPLATE SPECIALIZATION ===\n";
    Box<int> b1(100);
    b1.print();

    Box<double> b2(3.14);
    b2.print();

    Box<bool> b3(true);
    b3.print();

    return 0;
}