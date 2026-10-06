#include <iostream>
#include <string>
using namespace std;

class TaiKhoan {
   private:
    int soTaiKhoan;
    string tenChuTaiKhoan;
    double soDu;

   public:
    TaiKhoan(int soTaiKhoan, string tenChuTaiKhoan, double soDu) {
        this->soTaiKhoan = soTaiKhoan;
        this->tenChuTaiKhoan = tenChuTaiKhoan;
        this->soDu = soDu;
    }

    void napTien(double soTien) { this->soDu += soTien; }

    void rutTien(double soTien) { this->soDu -= soTien; }

    void hienThi() {
        cout << "========== THONG TIN TAI KHOAN ==========" << endl;
        cout << "So tai khoan: " << soTaiKhoan << "; \nTen chu tai khoan: " << tenChuTaiKhoan
             << endl;
        cout << "So du hien tai: " << soDu;
    }

    TaiKhoan& capNhatTen(string tenMoi) {
        this->tenChuTaiKhoan = tenMoi;
        return *this;
    }

    ~TaiKhoan() {
        cout << "\nDa giai phong bo nho thanh cong cua nguoi dung: " << tenChuTaiKhoan << endl;
    }
};

int main() {
    int stk;
    string ten;
    double sdtk;

    cout << "Nhap so tai khoan: ";
    cin >> stk;
    cin.ignore();
    cout << "Nhap ten chu tao khoan: ";
    getline(cin, ten);
    cout << "Nhap so du hien co: ";
    cin >> sdtk;

    TaiKhoan tk1(stk, ten, sdtk);
    tk1.hienThi();

    double soTienNap;
    cout << "\nNhap so tien muon nap: ";
    cin >> soTienNap;
    tk1.napTien(soTienNap);
    tk1.hienThi();

    double soTienRut;
    cout << "\nNhap so tien can rut: ";
    cin >> soTienRut;
    tk1.rutTien(soTienRut);
    tk1.hienThi();

    cout << "\n========== CAP NHAT TEN ==========" << endl;
    tk1.capNhatTen("Truc").capNhatTen("Mai").hienThi();

    return 0;
}