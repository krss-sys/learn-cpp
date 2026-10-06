#include <iostream>
using namespace std;

class MangSo {
   private:
    int* arr;
    int size;

   public:
    // Constructor
    MangSo(int n) {
        size = n;
        arr = new int[size];
        cout << "Constructor chay!" << endl;
    }

    // Copy constructor (deep copy)
    MangSo(const MangSo& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        cout << "Copy constructor (deep copy) chay" << endl;
    }

    // Nhap gia tri
    void nhap() {
        cout << "Nhap " << size << " so: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // In gia tri
    void xuat() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~MangSo() {
        delete[] arr;
        cout << "Destructor chay!" << endl;
    }
};

int main() {
    cout << "=== Tao mang 1 ===" << endl;
    MangSo m1(3);
    m1.nhap();

    cout << "\n=== Tao mang 2 tu mang 1 (copy constructor) ===" << endl;
    MangSo m2 = m1;  // deep copy
    m2.xuat();

    cout << "=== Ket thuc main ===" << endl;
    // deestructor

    return 0;
}