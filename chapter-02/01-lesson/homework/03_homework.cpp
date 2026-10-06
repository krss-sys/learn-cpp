#include <iostream>
#include <string>
using namespace std;

void nhapDiem(double &toan, double &van, double &anh);
void tinhKetQua(double toan, double van, double anh, double &diemTb, string &loai);
void doiXepLoai(string &loai1, string &loai2);
void inKetQua(const string &ten, const double &toan, const double &van, const double &anh,
              const double &diemTB, const string &xepLoai);

int main() {
    string ten, loai, loaiMuonDoi;
    double toan, van, anh, diemTb;

    // Nhap ten hoc sinh
    cout << "Nhap ten hoc sinh: ";
    getline(cin, ten);

    // Nhap 3 diem
    nhapDiem(toan, van, anh);

    // Tinh ket qua, Xep loai
    tinhKetQua(toan, van, anh, diemTb, loai);

    // Doi xep loai
    cout << "Nhap loai xep hang muon doi: ";
    cin >> loaiMuonDoi;
    doiXepLoai(loai, loaiMuonDoi);

    // In ket qua
    inKetQua(ten, toan, van, anh, diemTb, loai);
    return 0;
}

void nhapDiem(double &toan, double &van, double &anh) {
    bool hopLe;

    do {
        hopLe = true;
        cout << "Nhap lan luot diem Toan, Van, Anh: ";
        cin >> toan >> van >> anh;

        if (toan < 0 || toan > 10) {
            cout << "Diem toan khong hop le!!!" << endl;
            hopLe = false;
        }
        if (van < 0 || van > 10) {
            cout << "Diem van khong hop le!!!" << endl;
            hopLe = false;
        }
        if (anh < 0 || anh > 10) {
            cout << "Diem anh khong hop le!!!" << endl;
            hopLe = false;
        }
        if (!hopLe) {
            cout << "Nhap lai ca 3 diem" << endl;
        }
    } while (!hopLe);
}

void tinhKetQua(double toan, double van, double anh, double &diemTb, string &loai) {
    diemTb = (toan + van + anh) / 3;
    if (diemTb >= 8.5)
        loai = "Gioi";
    else if (diemTb >= 7.0)
        loai = "Kha";
    else if (diemTb >= 5.0)
        loai = "Trung binh";
    else
        loai = "Yeu";
    cout << "Xep Loai: " << loai << endl;
}

void doiXepLoai(string &loai1, string &loai2) {
    string temp = loai1;
    loai1 = loai2;
    loai2 = temp;
}

void inKetQua(const string &ten, const double &toan, const double &van, const double &anh,
              const double &diemTB, const string &xepLoai) {
    cout << "\n==========Thong tin hoc sinh==========" << endl;
    cout << "Ten hoc sinh: " << ten << endl;
    cout << "Toan: " << toan << ", Van: " << van << ", Anh: " << anh << endl;
    cout << "Diem trung binh mon: " << diemTB << ", Xep loai: " << xepLoai << endl;
}
