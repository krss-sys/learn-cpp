#include <iostream>
#include <string>
using namespace std;

class SanPham {
   private:
    int maSanPham, soLuong;
    string tenSanPham;
    double gia;

   public:
    SanPham() {
        maSanPham = 0;
        tenSanPham = "Chua co ten";
        gia = 0;
        soLuong = 0;
    }

    SanPham(int ma, int sl, string ten, double giaTri)
        : maSanPham(ma), soLuong(sl), tenSanPham(ten), gia(giaTri) {}

    void nhap() {
        cout << "Nhap ma san pham: ";
        cin >> maSanPham;
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, tenSanPham);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap gia: ";
        cin >> gia;
    }

    void xuat() {
        cout << "=== THONG TIN DON HANG ===" << endl;
        cout << "Hang hoa: " << tenSanPham << "; MaSP: " << maSanPham << endl;
        cout << "So luong: " << soLuong << "; Gia tri (1 don vi): " << gia << endl;
    }

    double tongGiaTri() { return gia * soLuong; }

    ~SanPham() { cout << "San pham [" << tenSanPham << "] da bi xoa" << endl; }
};

int main() {
    double tong;
    cout << "=== San pham 1 (constructor mac dinh) ===" << endl;
    SanPham sp1;
    sp1.xuat();

    cout << "=== San Pham 2 (constructor tham so) ===" << endl;
    SanPham sp2;
    sp2.nhap();
    sp2.xuat();

    tong = sp2.tongGiaTri();
    cout << "Tong tien hang cua don hang sp 2: " << tong << endl;
    // auto chay destructor

    return 0;
}