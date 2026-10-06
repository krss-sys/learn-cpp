#include <iostream>
#include <string>
using namespace std;

// ========== PHAN 1: PURE VIRTUAL CO BAN =========
// abstract class (vi co pure virtual)
class DongVat {
   public:
    virtual void tiengKeu() = 0;  // pure virtual
};

class Cho : public DongVat {
   public:
    void tiengKeu() override { cout << "Gau gau!!!" << endl; }
};

class Meo : public DongVat {
   public:
    void tiengKeu() override { cout << "Meo meo!!!" << endl; }
};

// ========== PHAN 2: ABSTRACT CLASS CO THUOC TINH + HAM THUONG =========
class Hinh {
   protected:
    string ten;

   public:
    Hinh(string t) : ten(t) {};

    virtual void tinhDienTich() = 0;

    void hienThiTen() { cout << "Hinh: " << ten << endl; }
};

class HinhTron : public Hinh {
   private:
    double banKinh;

   public:
    HinhTron(string t, double r) : Hinh(t), banKinh(r) {}

    void tinhDienTich() override {
        cout << "Dien tich hinh tron: " << 3.14 * banKinh * banKinh << endl;
    }
};

int main() {
    cout << "=== PHAN 1: PURE VIRTUAL CO BAN ===" << endl;
    Cho cho;
    Meo meo;
    cho.tiengKeu();
    meo.tiengKeu();

    cout << "\n=== PHAN 2: ABSTRACT CLASS CO THUOC TINH ===" << endl;
    HinhTron ht("Hinh tron", 5);
    ht.hienThiTen();
    ht.tinhDienTich();

    return 0;
}