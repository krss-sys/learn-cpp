#include <iostream>
#include <string>
using namespace std;

class NhanVien {
   private:
    const int maNV;
    string ten;
    double luongCoBan;
    static int tongSoNV;

   public:
    NhanVien(int ma, string t, double luong) : maNV(ma), ten(t), luongCoBan(luong) {
        tongSoNV++;
        cout << "Tong so Nhan vien hien tai: " << tongSoNV << endl;
    }

    void hienThi() const {
        cout << "Ten nhan vien: " << ten << "; Ma so: " << maNV << "; Muc luong: " << luongCoBan
             << " VND" << endl;
    }

    double tinhLuong() const { return luongCoBan * 1.1; }

    static int laySoLuong() { return tongSoNV; }

    ~NhanVien() {
        tongSoNV--;
        cout << "So nhan vien con lai: " << tongSoNV << endl;
    }
};

int NhanVien ::tongSoNV = 0;

int main() {
    NhanVien nv1(2200170, "Kiet", 300000);
    NhanVien nv2(7746297, "Mai", 200000);
    NhanVien nv3(3645482, "Hung", 560000);

    nv1.hienThi();
    nv2.hienThi();
    nv3.hienThi();

    cout << "Tong so nhan vien: " << NhanVien ::laySoLuong() << endl;

    NhanVien nv4(64748926, "Trang", 1000000);
    cout << "Tong so nhan vien sau cap nhat: " << NhanVien ::laySoLuong() << endl;

    return 0;
}