#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int matrix[3][3];

    cout << "Nhap " << rows * cols << " so: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "=== MATRAN ===" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "=== Tinh Tong ===" << endl;
    int tong = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tong += matrix[i][j];
        }
    }
    cout << "Tong la: " << tong << endl;

    cout << "=== Tim GTLN ===" << endl;
    int GTLN = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (GTLN < matrix[i][j]) {
                GTLN = matrix[i][j];
            }
        }
    }
    cout << "GTLN la: " << GTLN << endl;

    cout << "===Tinh gia tri tung hang===" << endl;
    for (int i = 0; i < rows; i++) {
        int tonghang = 0;
        for (int j = 0; j < cols; j++) {
            tonghang += matrix[i][j];
        }
        cout << "Tong hang " << i << ": " << tonghang << endl;
    }
    cout << endl;
    return 0;
}