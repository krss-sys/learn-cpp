#include <iostream>
using namespace std;

int main() {
    cout << "=== 1. LAY DIA CHI CO BAN ===" << endl;
    int x = 5;
    double y = 3.14;
    char z = 'A';

    cout << "Gia tri cua x: " << x << endl;
    cout << "Dia chi cua x: " << &x << endl;
    cout << "Dia chi cua y: " << &y << endl;
    cout << "Dia chi cua z: " << (void *)&z << endl;

    cout << "=== 2. SO SANH DIA CHI CAC BIEN ===" << endl;
    int a = 10, b = 20, c = 30;
    cout << "Dia chi cua a: " << &a << endl;
    cout << "Dia chi cua b: " << &b << endl;
    cout << "Dia chi cua c: " << &c << endl;
    cout << "Cac dia chi thuong cach nhau 4 byte (int 4 byte)" << endl;

    cout << " 3. DIA CHI VA THAM CHIEU ===" << endl;
    int value = 100;
    int &ref = value;  // tham chieu
    cout << "Dia chi cua value: " << &value << endl;
    cout << "Dia chi cua ref: " << &ref << endl;  // Giong nhau

    cout << "=== 4. KICH THUOC DIA CHI ===" << endl;
    cout << "sizeof(&x): " << sizeof(&x) << " byte" << endl;
    cout << "Tren he 64-bit, dia chi thuong la 8 byte" << endl;

    return 0;
}