#include <iostream>
using namespace std;

class MangSo {
   private:
    int* arr;
    int size;

   public:
    // Constructor mac dinh
    MangSo() {
        size = 0;
        arr = nullptr;
        cout << "Constructor mac dinh chay!" << endl;
    }

    // Constructor
    MangSo(int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i * 10;
        }
        cout << "Constructor chay!" << endl;
    }

    // Copy constructor (deep copy)
    MangSo(const MangSo& other) {
        this->size = other.size;
        arr = new int[this->size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = other.arr[i];
        }
        cout << "Copy constructor dang chay" << endl;
    }

    // Assigment operator (deep copy)
    MangSo& operator=(const MangSo& other) {
        if (this != &other) {
            delete[] arr;
            this->size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
            cout << "Assigment operator chay!" << endl;
        }
        return *this;
    }

    // Destructor
    ~MangSo() {
        delete[] arr;
        cout << "Da destructor!" << endl;
    }

    void hienThi() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Tao mang 1 ===" << endl;
    MangSo mang1(3);
    mang1.hienThi();

    cout << "\n=== Tao mang2 = mang1 (copy constructor) ===" << endl;
    MangSo mang2 = mang1;
    mang2.hienThi();

    cout << "\n== Tao mang3 rong, roi gan = mang 1 (assigment) ===" << endl;
    MangSo mang3;  // Constructor mac dinh
    mang3 = mang1;
    mang3.hienThi();

    return 0;
}