#include <iostream>
using namespace std;

int main() {
    // ======================Khai bao va khoi tao========================
    cout << "=== Phan 1: Khai bao va khoi tao ===" << endl;

    // Cach 1: Khai bao khong khoi tao
    int arr1[5];
    // Cach 2: Khoi tao toan bo
    int arr2[5] = {10, 20, 30, 40, 50};
    // Cach 3: Khoi tao 1 phan
    int arr3[5] = {10, 20, 30};
    // Cach 4: Khong ghi kich thuoc
    int arr4[] = {100, 200, 300};
    // Cach 5: Khoi tao tat ca bang 0
    int arr5[5] = {0};

    // In arr2
    cout << "arr2: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // ===================== Truy cap phan tu ============================
    cout << "\n=== Phan 2: Truy cap phan tu ===" << endl;
    int arr[5] = {5, 10, 15, 20, 25};
    cout << "Phan tu dau tien (arr[0]): " << arr[0] << endl;
    cout << "Phan tu thu 3 (arr[2]): " << arr[2] << endl;
    cout << "Phan tu cuoi cung (arr[4]): " << arr[4] << endl;

    // Thay doi gia tri
    arr[1] = 99;
    cout << "sau khi sua cua arr[1]: " << arr[1] << endl;

    // =============== Phan 3: Duyet mang vong lap for===================
    cout << "\n=== Phan 3: Duyet mang bang vong lap For ===" << endl;
    int number[5] = {2, 4, 6, 8, 10};
    // Duyet xuoi
    cout << "Duyet xuoi: ";
    for (int i = 0; i < 5; i++) {
        cout << number[i] << " ";
    }
    cout << endl;
    // Duyet nguoc
    cout << "Duyet nguoc: ";
    for (int i = 4; i >= 0; i--) {
        cout << number[i] << " ";
    }
    cout << endl;

    //=================== Phan 4: Nhap mang tu ban phim =================
    cout << "\n=== Phan 4: Nhap mang tu ban phim===" << endl;
    const int SIZE = 5;
    int data[SIZE];
    cout << "Nhap " << SIZE << " so nguyen: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> data[i];
    }
    cout << "Mang vua nhap: ";
    for (int i = 0; i < SIZE; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}