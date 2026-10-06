#include <iostream>
#include <string>
using namespace std;

class SinhVien {
   private:
    const int maSo;  // const: khong doi
    string ten;
    static int soLuong;  // static: dung chung

   public:
    // Constructor: khoi tao const bang initializer lust
    SinhVien(int ma, string t) : maSo(ma), ten(t) { soLuong++; }

    // Ham const: khong sua thuoc tinh
    void hienThi() const { cout << "Ma so: " << maSo << "; Ten: " << ten << endl; }

    // Ham static: chi truy cap static
    static int laySoLuong() { return soLuong; }

    ~SinhVien() { soLuong--; }
};

// Dinh nghia static
int SinhVien ::soLuong = 0;

int main() {
    cout << "=== STATIC + CONST DEMO ===" << endl;
    SinhVien sv1(20, "Kiet");
    SinhVien sv2(30, "Mai");

    sv1.hienThi();
    sv2.hienThi();

    cout << "TONG SO SINH VIEN: " << SinhVien::laySoLuong() << endl;

    return 0;
}