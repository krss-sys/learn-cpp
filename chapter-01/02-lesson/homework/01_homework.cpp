#include <iostream>
using namespace std;

int main() {
    double toan, van, anh;

    cout << "Nhap diem lan luot toán văn anh: " << endl;
    cin >> toan >> van >> anh;
    auto diem_tb = (toan + van + anh) / 3;
    cout << "Diem trung binh mon: " << diem_tb << endl;
    if (diem_tb >= 8) {
        cout << "Ban nhan duoc danh hieu hoc sinh gioi" << endl;
    } else if (diem_tb >= 6.5) {
        cout << "BAn nhan duoc danh hieu hoc sinh kha" << endl;
    } else if (diem_tb >= 5) {
        cout << "Ban nhan duoc danh hieu hoc sinh trung binh" << endl;
    } else {
        cout << "Thang ngu hoc sinh kem" << endl;
    }
    return 0;
}