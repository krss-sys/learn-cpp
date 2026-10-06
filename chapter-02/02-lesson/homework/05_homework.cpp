#include <iostream>
using namespace std;

int* nhapDanhSach(int& n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Nhap " << n << " so: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

void inDanhSach(int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
}

int tinhTong(int* arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}

int timSoLonNhat(int* arr, int n) {
    int GTLN = arr[0];
    for (int i = 0; i < n; i++) {
        if (GTLN < arr[i]) {
            GTLN = arr[i];
        }
    }
    return GTLN;
}

int* danhSachMoi(int* arr, int n, int& newSize) {
    do {
        cout << "Nhap so phan tu cua mang moi: ";
        cin >> newSize;
        if (newSize > n) {
            break;
        } else {
            cout << "Loi: so phan tu mang moi khong duoc nho hon mang cu" << endl;
        }
    } while (true);

    int* newArr = new int[newSize];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }
    for (int i = n; i < newSize; i++) {
        cout << "Them so moi vao newArr[" << i << "]";
        cin >> newArr[i];
    }
    return newArr;
}

int main() {
    int n, tong, GTLN, newsize;
    int* arr = nhapDanhSach(n);
    inDanhSach(arr, n);
    tong = tinhTong(arr, n);
    GTLN = timSoLonNhat(arr, n);
    int* mangMoi = danhSachMoi(arr, n, newsize);
    inDanhSach(mangMoi, newsize);
    delete[] arr;
    arr = nullptr;
    delete[] mangMoi;
    mangMoi = nullptr;

    return 0;
}