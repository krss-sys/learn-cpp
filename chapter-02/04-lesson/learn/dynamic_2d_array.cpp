#include <iostream>
using namespace std;

int main() {
    cout << "=== CAP PHAT MANG 2 CHIEU DONG ===" << endl;

    int rows, cols;
    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot: ";
    cin >> cols;

    // 1. Cap phat mang 2 chieu dong
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    // 2. Nhao gia tri
    cout << "Nhap " << rows << " x " << cols << " so: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    // 3. In ma tran
    cout << "Ma tran vua nhap: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    // 4. Tinh tong
    int tong = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tong += matrix[i][j];
        }
    }
    cout << "Tong cac phan tu: " << tong << endl;
    // 5. Giai phong bo nho
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    cout << "Da giai phong bo nho!" << endl;

    return 0;
}
