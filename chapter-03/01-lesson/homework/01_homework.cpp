#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string ten;
    int tuoi;
    float diem;
};

int main() {
    SinhVien sv1;
    SinhVien sv2;

    cout << "Nhap lan luot ten sinh vien 1 va 2: ";
    cin >> sv1.ten >> sv2.ten;

    cout << "Nhap lan luot tuoi sinh vien 1 va 2: ";
    cin >> sv1.tuoi >> sv2.tuoi;

    cout << "Nhap lan luot diem sinh vien 1 va 2: ";
    cin >> sv1.diem >> sv2.diem;
    
    cout << "=== THONG TIN SINH VIEN ===" << endl;
    cout << "Ten sinh vien 1: " << sv1.ten << ", Tuoi: " << sv1.tuoi << ", Diem: " << sv1.diem << endl;
    cout << "Ten sinh vien 2: " << sv2.ten << ", Tuoi: " << sv2.tuoi << ", Diem: " << sv2.diem << endl;

    return 0;
}