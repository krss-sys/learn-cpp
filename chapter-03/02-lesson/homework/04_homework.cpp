#include <iostream>
#include <string>
using namespace std;

class NhanVatGame {
   private:
    string ten;
    int mau;
    int satThuong;
    int capDo;

   public:
    NhanVatGame(string name, int hp, int dame, int level)
        : ten(name), mau(hp), satThuong(dame), capDo(level) {}

    ~NhanVatGame() { cout << "Da destructor thanh cong !!!" << endl; }

    void hienThi() {
        cout << "=== THONG TIN NHAN VAT ===" << endl;
        cout << "Nhan vat: " << ten << "; Cap do: " << capDo << endl;
        cout << "Mau: " << mau << "; Sat thuong: " << satThuong << endl;
    }

    friend void tanCong(NhanVatGame& keTanCong, NhanVatGame& mucTieu);

    friend void hoiMau(NhanVatGame& nv, int luong);
};

void tanCong(NhanVatGame& keTanCong, NhanVatGame& mucTieu) {
    mucTieu.mau -= keTanCong.satThuong;
    cout << keTanCong.ten << " da tan cong " << mucTieu.ten << " !!!" << endl;
    cout << "Mau con lai cua " << mucTieu.ten << ": " << mucTieu.mau << endl;
    if (mucTieu.mau <= 0) {
        cout << mucTieu.ten << " da bi ha guc" << endl;
    }
}

void hoiMau(NhanVatGame& nv, int luong) {
    nv.mau += luong;
    cout << nv.ten << " da duoc hoi mau" << endl;
    cout << "Mau cua nhan vat hien tai: " << nv.mau << endl;
}

int main() {
    NhanVatGame nv1("Kiet", 10000, 100, 10);
    NhanVatGame nv2("Hung", 20000, 200, 20);
    nv1.hienThi();
    nv2.hienThi();

    tanCong(nv1, nv2);
    nv1.hienThi();
    nv2.hienThi();
    hoiMau(nv2, 20);

    tanCong(nv2, nv1);
    nv1.hienThi();
    nv2.hienThi();

    return 0;
}