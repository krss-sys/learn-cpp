#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a;

    cout << "Gia tri cua a: " << a << endl;
    cout << "Dia chi cua a: " << &a << endl;
    cout << "Gia tri cuar ptr: " << ptr << endl;
    cout << "Gia tri cua *ptr: " << *ptr << endl;

    *ptr = 99;
    cout << "Gia tri cuar a sau khi doi: " << a << endl;
    cout << "Gia tri cua *ptr sau khi doi: " << *ptr << endl;

    return 0;
}