#include <iostream>
#include <string>
using namespace std;

class NhanVien {
   protected:
    string ten;
    double luongCoBan;

   public:
    NhanVien(string name, double money) : ten(name), luongCoBan(money) {}

    virtual ~NhanVien() { cout << "Da destructor " << ten << endl; }

    virtual double tinhLuong() = 0;

    void hienThi() {
        cout << "Nhan vien: " << ten << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Tong luong thuc nhan: " << tinhLuong() << endl;
    }
};

class NhanVienVanPhong : public NhanVien {
   private:
    int soNgayLam;

   public:
    NhanVienVanPhong(string name, double money, int day) : NhanVien(name, money), soNgayLam(day) {}

    virtual ~NhanVienVanPhong() { cout << "Da destructor " << ten << endl; }

    double tinhLuong() override { return luongCoBan * soNgayLam; }
};

class NhanVienBanHang : public NhanVien {
   private:
    double doanhSo;
    double tiLeHoaHong;

   public:
    NhanVienBanHang(string name, double money, double ds, double tl)
        : NhanVien(name, money), doanhSo(ds), tiLeHoaHong(tl) {}

    virtual ~NhanVienBanHang() { cout << "Da destructor " << ten << endl; }

    double tinhLuong() override { return luongCoBan + doanhSo * tiLeHoaHong; }
};

int main() {
    NhanVienVanPhong vp("Hung", 100000, 30);
    NhanVienBanHang bh("Trang", 30000, 2000000, 0.05);
    vp.hienThi();
    bh.hienThi();

    return 0;
}