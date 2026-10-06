#include <iostream>
using namespace std;

int main() {
    cout << "=== 1. IN DIA CHI ===" << endl;
    int a = 10;
    float b = 3.14;
    double c = 2.718;
    char d = 'Z';
    cout << "Gia tri cua a: " << a << endl;
    cout << "Dia chi cua a: " << &a << endl;
    cout << "Gia tri cua b: " << b << endl;
    cout << "Dia chi cua b: " << &b << endl;
    cout << "Gia tri cua c: " << c << endl;
    cout << "Dia chi cua c: " << &c << endl;
    cout << "Gia tri cua d: " << d << endl;
    cout << "Dia chi cua d: " << (void *)&d << endl;

    cout << "\n=== 2. DIA CHI VA THAM CHIEU ===" << endl;
    int value = 100;
    int &ref = value;
    cout << "Dia chi cua value: " << &value << endl;
    cout << "Gia tri cua value: " << value << endl;
    cout << "Dia chi cua ref: " << &ref << endl;
    cout << "Gia tri cua ref: " << ref << endl;
    ref = 200;
    cout << "Dia chi cua value: " << &value << endl;
    cout << "Gia tri cua value: " << value << endl;
    cout << "Dia chi cua ref: " << &ref << endl;
    cout << "Gia tri cua ref: " << ref << endl;

    cout << "\n=== 3. KICH THUOC ===" << endl;
    string ten = "kiet";
    cout << "Kich thuoc cua int: " << sizeof(int) << endl;
    cout << "Kich thuoc cua double: " << sizeof(double) << endl;
    cout << "Kich thuoc cua char: " << sizeof(char) << endl;
    cout << "Kich thuoc cua ten: " << sizeof(ten) << endl;
    cout << "Do dai cua ten: " << ten.size() << endl;
    cout << "Kich thuoc dia chi cua ten: " << sizeof(&ten) << endl;

    return 0;
}