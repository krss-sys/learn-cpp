#include <iostream>
#include <string>
using namespace std;

class Hinh {
   protected:
    string ten;

   public:
    Hinh(string name) : ten(name) {}

    ~Hinh() {}

    virtual void tinhDienTich() { cout << "Dien tich cua hinh chua duoc dinh nghia!!!" << endl; }

    void hienThiTen() { cout << "Hinh: " << ten << endl; }
};

class HinhTron : public Hinh {
   private:
    double banKinh;

   public:
    HinhTron(string name, double bk) : Hinh(name) { banKinh = bk; }

    ~HinhTron() {}

    void tinhDienTich() override {
        cout << "Dien tich hinh tron: " << 3.14 * banKinh * banKinh << endl;
    }
};

class HinhVuong : public Hinh {
   private:
    double canh;

   public:
    HinhVuong(string name, double c) : Hinh(name), canh(c) {}

    ~HinhVuong() {}

    void tinhDienTich() override { cout << "Dien tich hinh vuong: " << canh * canh << endl; }
};

int main() {
    HinhTron ht("Hinh tron", 3);
    HinhVuong hv("Hinh vuong", 5);

    ht.tinhDienTich();
    hv.tinhDienTich();

    Hinh* ptr1 = new HinhTron("Hinh tron", 3);
    Hinh* ptr2 = new HinhVuong("Hinh vuong", 5);

    ptr1->tinhDienTich();
    ptr2->tinhDienTich();

    delete ptr1;
    delete ptr2;

    return 0;
}