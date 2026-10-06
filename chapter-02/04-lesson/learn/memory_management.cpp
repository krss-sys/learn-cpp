#include <iostream>
using namespace std;
int main() {
    int rows = 2, cols = 3;

    // 1. Cap phat mang 2 chieu dong
    double** diem = new double*[rows];
    for (int i = 0; i < rows; i++) {
        diem[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            diem[i][j] = (i + 1) * (j + 1);
        }
    }

    // 2. In mang
    cout << "Ma tran ban dau: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << diem[i][j] << " | ";
        }
        cout << endl;
    }

    // 3. Them 1 hoc sinh ( tang rows)
    int newRows = rows + 1;
    double** newDiem = new double*[newRows];
    for (int i = 0; i < rows; i++) {
        newDiem[i] = diem[i];  // copy dia chi khong copy gia tri
    }
    newDiem[rows] = new double[cols];
    for (int j = 0; j < cols; j++) {
        newDiem[rows][j] = 99;
    }

    delete[] diem;
    diem = newDiem;
    rows = newRows;

    // 4. In mang moi
    cout << "\nMa tran sau khi them 1 hoc sinh: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << diem[i][j] << " | ";
        }
        cout << endl;
    }

    // 5. Giai phong bo nho
    for (int i = 0; i < rows; i++) {
        delete[] diem[i];
    }
    delete[] diem;
    diem = nullptr;

    cout << "\nDa giai phong bo nho" << endl;

    return 0;
}