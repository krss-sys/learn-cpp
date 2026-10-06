#include <iostream>
#include <string>
using namespace std;

class Xe {
   protected:
    string hangXe;
    int namSanXuat;
    double giaBan;

   public:
    Xe(string name, int year, double cost) : hangXe(name), namSanXuat(year), giaBan(cost) {}

    void hienThi() {
        cout << "Hang xe: " << hangXe << "; Nam san xuat: " << namSanXuat << "; Gia: " << giaBan
             << " VND" << endl;
    }
};

class XeMay : public Xe {
   private:
    int dungTich;

   public:
    XeMay(string name, int year, double cost, int dt) : Xe(name, year, cost) { dungTich = dt; }

    void hienThi() {
        Xe ::hienThi();
        cout << "Dung tich: " << dungTich << " cc" << endl;
    }
};

class OTo : public Xe {
   private:
    int soChoNgoi;

   public:
    OTo(string name, int year, double cost, int number) : Xe(name, year, cost) {
        soChoNgoi = number;
    }

    void hienThi() {
        Xe ::hienThi();
        cout << "So cho ngoi: " << soChoNgoi << endl;
    }
};

int main() {
    XeMay xm("Honda", 2004, 700000000, 30);
    OTo car("Lambo", 2010, 1000000000, 4);
    xm.hienThi();
    car.hienThi();

    return 0;
}