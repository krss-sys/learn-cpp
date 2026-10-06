#include <iostream>
#include <string>

template <typename T>
class Box {
   private:
    T value;

   public:
    Box(T val) : value(val) {}

    ~Box() { std::cout << value << " Destructor thanh cong\n"; }

    T getValue() const { return value; }

    void setValue(T val) { value = val; }

    void print() const { std::cout << "value: " << value << "\n"; }
};

int main() {
    Box<int> t1(10);
    Box<std::string> t2("Hello");
    Box<double> t3(3.14);
    std::cout << "value t1 la " << t1.getValue() << "\n";
    std::cout << "value t2 la " << t2.getValue() << "\n";
    std::cout << "value t3 la " << t3.getValue() << "\n";

    t1.setValue(100);
    t2.setValue("Kiet");
    t3.setValue(2.89);

    t1.print();
    t2.print();
    t3.print();

    return 0;
}