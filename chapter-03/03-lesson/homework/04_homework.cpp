#include <iostream>
#include <string>
using namespace std;

class SanPham {
   protected:
    string ten;
    double gia;

   public:
    SanPham(string name, double cost) : ten(name), gia(cost) {}

    virtual void hienThi() = 0;

    virtual double tinhGiamGia() = 0;

    virtual ~SanPham() {}
};

class DienTu : public SanPham {
   private:
    int baoHanh;

   public:
    DienTu(string name, double cost, int month) : SanPham(name, cost), baoHanh(month) {}

    void hienThi() override {
        cout << "Ten san pham: " << ten << endl;
        cout << "Gia san pham: " << gia << endl;
        cout << "Thoi gian bao hanh: " << baoHanh << " thang" << endl;
    }

    double tinhGiamGia() override {
        if (gia > 1000000) {
            return gia * 0.9;
        } else {
            return gia;
        }
    }
};

class QuanAo : public SanPham {
   private:
    string chatLieu;

   public:
    QuanAo(string name, double cost, string cl) : SanPham(name, cost), chatLieu(cl) {}

    void hienThi() override {
        cout << "Ten san pham: " << ten << endl;
        cout << "Gia san pham: " << gia << endl;
        cout << "Chat lieu: " << chatLieu << endl;
    }

    double tinhGiamGia() override {
        if (gia > 500000) {
            return gia * 0.95;
        } else {
            return gia;
        }
    }
};

void inThongTin(SanPham& sp) {
    sp.hienThi();
    cout << "Gia tri thanh toan (sau giam gia): " << sp.tinhGiamGia() << endl;
}

int main() {
    cout << "========== DA HINH QUA CON TRO ==========" << endl;
    SanPham* sp[2];
    sp[0] = new DienTu("May quat", 3000000, 12);
    sp[1] = new QuanAo("Do ngu", 700000, "Vai");

    for (int i = 0; i < 2; i++) {
        sp[i]->hienThi();
        cout << "Gia sau khi giam: " << sp[i]->tinhGiamGia() << endl;
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete sp[i];
    }

    cout << "\n========== DA HINH QUA THAM CHIEU =========" << endl;
    DienTu dt("Tu lanh", 5000000, 6);
    QuanAo qa("Do boi", 900000, "Nilon");

    inThongTin(dt);
    cout << endl;
    inThongTin(qa);

    return 0;
}