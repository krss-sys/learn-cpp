#include <iostream>
#include <string>
using namespace std;

// Khai báo nguyên mẫu hàm
void nhapDiem(double &diem);
void tinhTong(double a, double b, double c, double &tong);  // Sửa lại: cần 3 điểm + 1 biến tong
void tinhTrungBinh(double tong, int soMon, double &trungBinh);
void xepLoai(double trungBinh, string &loai);
void inKetQua(const string &ten, double trungBinh, const string &loai);

int main() {
    string ten, loai;
    double diemToan, diemVan, diemAnh, tong, trungBinh;

    cout << "Hay nhap ten hoc sinh: ";
    getline(cin, ten);

    cout << "Hay nhap diem toan: ";
    nhapDiem(diemToan);
    cout << "Hay nhap diem van: ";
    nhapDiem(diemVan);
    cout << "Hay nhap diem anh: ";
    nhapDiem(diemAnh);

    tinhTong(diemToan, diemVan, diemAnh, tong);  // Gọi đúng 4 tham số

    int soMon = 3;
    tinhTrungBinh(tong, soMon, trungBinh);
    xepLoai(trungBinh, loai);
    inKetQua(ten, trungBinh, loai);

    return 0;
}

// Định nghĩa các hàm
void nhapDiem(double &diem) {
    cin >> diem;
    while (diem < 0 || diem > 10) {
        cout << "Nhap sai, nhap lai: ";
        cin >> diem;
    }
}

void tinhTong(double a, double b, double c, double &tong) { tong = a + b + c; }

void tinhTrungBinh(double tong, int soMon, double &trungBinh) { trungBinh = tong / soMon; }

void xepLoai(double trungBinh, string &loai) {
    if (trungBinh >= 8)
        loai = "Gioi";
    else if (trungBinh >= 6.5)
        loai = "Kha";
    else
        loai = "Trung binh";
}

void inKetQua(const string &ten, double trungBinh, const string &loai) {
    cout << "\n--- Ket qua ---" << endl;
    cout << "Hoc sinh: " << ten << endl;
    cout << "Diem trung binh: " << trungBinh << endl;
    cout << "Xep loai: " << loai << endl;
}