#include <iostream>
using namespace std;

double** nhapDiem(int& rows, int& cols) {
    cout << "Nhap so hoc sinh: ";
    cin >> rows;
    cout << "Nhap so mon: ";
    cin >> cols;

    double** diem = new double*[rows];
    for (int i = 0; i < rows; i++) {
        diem[i] = new double[cols];
    }

    cout << "Nhap lan luot " << rows * cols << " diem: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                cin >> diem[i][j];
                if (diem[i][j] < 0 || diem[i][j] > 10) {
                    cout << "Loi: Diem khong hop le!!!" << endl;
                }
            } while (diem[i][j] < 0 || diem[i][j] > 10);
        }
    }
    return diem;
}

void tinhDiem(double** diem, int rows, int cols) {
    double diemTbMax = -1;
    int viTriMax = 0;
    for (int i = 0; i < rows; i++) {
        double tong = 0;
        double diemTb = 0;
        cout << "Diem cua em: [" << i << "]" << endl;
        for (int j = 0; j < cols; j++) {
            tong += diem[i][j];
        }
        diemTb = tong / cols;
        cout << "Diem trung binh cua em: [" << i << "]: " << diemTb << endl;
        if (diemTb > diemTbMax) {
            diemTbMax = diemTb;
            viTriMax = i;
        }
    }
    cout << "Hoc sinh co diem trung binh cao nhat: [" << viTriMax << "], voi so diem " << diemTbMax
         << endl;
}

void tinhTb(double** diem, int rows, int cols) {
    cout << "\nTinh trung binh tung mon" << endl;
    for (int j = 0; j < cols; j++) {
        double tong = 0;
        for (int i = 0; i < rows; i++) {
            tong += diem[i][j];
        }
        double tb = tong / rows;
        cout << "Mon " << j << ": " << tb << endl;
    }
}

int main() {
    int cot, hang;
    double** bangDiem;
    bangDiem = nhapDiem(hang, cot);
    tinhDiem(bangDiem, hang, cot);
    tinhTb(bangDiem, hang, cot);
    for (int i = 0; i < hang; i++) {
        delete[] bangDiem[i];
    }
    delete[] bangDiem;
    bangDiem = nullptr;
    cout << "Da giai phong bo nho";

    return 0;
}