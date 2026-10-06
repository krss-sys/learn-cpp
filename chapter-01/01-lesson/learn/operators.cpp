#include <iostream>
using namespace std;

int main() {
    // Phan A: So hoc
    int a = 10, b = 3;
    cout << "===Toan tu so hoc===" << endl;
    cout << "a + b= " << a + b << endl;
    cout << "a - b= " << a - b << endl;
    cout << "a * b= " << a * b << endl;
    cout << "a / b= " << a / b << endl;
    cout << "a % b= " << a % b << endl;

    // Phan B: So sanh
    cout << boolalpha;
    cout << "\n===Toan tu so sanh===" << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;

    // Phan C: Logic
    cout << boolalpha;
    bool p = true, q = false;
    cout << "\n===Toan tu Logic===" << endl;
    cout << "p && q: " << (p && q) << endl;
    cout << "p || q: " << (p || q) << endl;
    cout << "!p: " << (!p) << endl;

    // Phan D: Bitwise
    int x = 5, y = 3;
    cout << "\n===Toan tu BITWISE===" << endl;
    cout << "5 & 3: " << (x & y) << endl;
    cout << "5 | 3: " << (x | y) << endl;
    cout << "5 << 1 = " << (x << 1) << endl;
    return 0;
}