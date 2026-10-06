#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Stack {
   private:
    std::vector<T> data;

   public:
    void push(T val) { data.push_back(val); }

    T pop() {
        if (data.empty()) {
            throw std::runtime_error("Stack rong!");
        }
        T val = data.back();
        data.pop_back();
        return val;
    }

    bool empty() const { return data.empty(); }

    int size() const { return data.size(); }

    void print() const {
        std::cout << "[ ";
        for (const T& x : data) {
            std::cout << x << " ";
        }
        std::cout << "] size = " << size() << "\n";
    }
};

template <typename T1, typename T2>
class Pair {
   private:
    T1 first;
    T2 second;

   public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void print() const { std::cout << "(" << first << ", " << second << ")" << "\n"; }
};

int main() {
    std::cout << "=== STACK<int> ===\n";
    Stack<int> stInt;
    stInt.push(10);
    stInt.push(20);
    stInt.push(30);
    stInt.print();

    std::cout << "pop: " << stInt.pop() << "\n";
    stInt.print();

    std::cout << "\n=== STACK<string> ===\n";
    Stack<std::string> stStr;
    stStr.push("Hello");
    stStr.push("World");
    stStr.print();

    std::cout << "pop: " << stStr.pop() << "\n";
    stStr.print();

    std::cout << "\n=== PAIR<int, string> ===\n";
    Pair<int, std::string> p1(1, "Mot");
    p1.print();

    std::cout << "\n=== PAIR<double, bool> ===\n";
    Pair<double, bool> p2(3.14, true);
    p2.print();

    return 0;
}