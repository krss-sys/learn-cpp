#include <iostream>
using namespace std;

int main() {
    cout << "=== 1. TEN MANG LA CON TRO ===" << endl;
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "arr: " << arr << endl;
    cout << "&arr[0]: " << &arr[0] << endl;
    cout << "arr va &arr[0] giong nhau" << endl;

    cout << "\n=== 2. CON TRO TRO DEN MANG ===" << endl;
    int* p = arr;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    cout << "\n=== 3. TRUY CAP PHAN TU QUA CON TRO ===" << endl;
    cout << "arr[2]: " << arr[2] << endl;
    cout << "*(arr + 2): " << *(arr + 2) << endl;
    cout << "p[2]: " << p[2] << endl;
    cout << "*(p + 2): " << *(p + 2) << endl;

    cout << "\n=== 4. DUYET MANG BANG CON TRO ===" << endl;
    cout << "Cach 1 (Chi so): ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Cach 2 (Con tro + offset): ";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    cout << "Cach 3 (Con tro truot): ";
    int* q = arr;
    for (int i = 0; i < 5; i++) {
        cout << *q << " ";
        q++;
    }
    cout << endl;

    cout << "\n=== 5. KHAC NHAU GIUA MANG VA CON TRO ===" << endl;
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "sizeof(p): " << sizeof(p) << endl;

    p = arr;
    return 0;
}
