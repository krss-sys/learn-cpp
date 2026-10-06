#include <iostream>
using namespace std;

int main() {
    int rows = 3;
    int cols = 4;
    int bangdiem[3][4];

    cout << "=== Nhap diem ===" << endl;
    cout << "Nhap diem cua cac hoc sinh: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> bangdiem[i][j];
        }
    }
    cout << endl;

    cout << "=== In bang diem ===" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Diem cua em " << i + 1 << " :";
        for (int j = 0; j < cols; j++) {
            cout << bangdiem[i][j] << " ";
        }
        cout << endl;
    }

    cout << "=== DIem trung binh ===" << endl;
    for (int i = 0; i < rows; i++) {
        int stt = i;
        int tong = 0;
        cout << "Diem trung binh cua em " << i + 1 << " :";
        for (int j = 0; j < cols; j++) {
            tong += bangdiem[i][j];
        }
        cout << static_cast<double>(tong) / 4 << endl;
    }
    cout << endl;

    cout << "=== DIem cao nhat ===" << endl;
    int GTLN = bangdiem[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (GTLN < bangdiem[i][j]) {
                GTLN = bangdiem[i][j];
            }
        }
    }
    cout << "DIem cao nhat la: " << GTLN << endl;

    cout << "===So diem duoi trung binh===" << endl;
    int dem = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (bangdiem[i][j] < 5) {
                dem++;
            }
        }
    }
    cout << dem << endl;

    return 0;
}