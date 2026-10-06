#include <iostream>
#include <vector>

template <typename T>
class Stack {
   private:
    std::vector<T> data;

   public:
    void push(T val) {
        data.push_back(val);
        std::cout << "Push chung: " << val << "\n";
    }

    T pop() {
        T val = data.back();
        data.pop_back();
        return val;
    }

    bool empty() const { return data.empty(); }
};

template <>
class Stack<bool> {
   private:
    std::vector<bool> data;

   public:
    void push(bool val) {
        data.push_back(val);
        std::cout << "Push rieng cho bool: " << (val ? "true" : "false");
    }

    bool pop() {
        bool val = data.back();
        data.pop_back();
        return val;
    }

    bool empty() const { return data.empty(); }
};

int main() {
    std::cout << "=== Stack<int> (tong quat) ===\n";
    Stack<int> stInt;
    stInt.push(10);
    stInt.push(20);

    std::cout << "\n=== Stack<bool> (specialization) ===\n";
    Stack<bool> stBool;
    stBool.push(true);
    stBool.push(false);

    return 0;
}