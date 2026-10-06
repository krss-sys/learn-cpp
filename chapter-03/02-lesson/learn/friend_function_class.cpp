#include <iostream>
#include <string>
using namespace std;

class SanPham {
   private:
    string ten;
    double gia;
    int soLuong;

   public:
    SanPham(string t, double g, int sl) : ten(t), gia(g), soLuong(sl) {}

    // Friend function
    friend void inTong(SanPham& sp);

    // Friend class
    friend class HoaDon;
};

// Friend function
void inTong(SanPham& sp) { cout << "Tong gia tri: " << sp.gia * sp.soLuong << " VND" << endl; }

// Friend class
class HoaDon {
   public:
    void inChiTiet(SanPham& sp) {
        cout << "Ten san pham: " << sp.ten << endl;
        cout << "Gia: " << sp.gia << endl;
        cout << "So luong: " << sp.soLuong << endl;
    }
};

int main() {
    SanPham sp1("chuot", 0.5, 100);

    cout << "=== FRIEND FUNCTION ===" << endl;
    inTong(sp1);

    cout << "\n=== FRIEND CLASS ===" << endl;
    HoaDon hd1;
    hd1.inChiTiet(sp1);

    return 0;
}