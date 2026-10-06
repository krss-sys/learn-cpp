#include <iostream>
using namespace std;

// Class cha
class DongVat {
   public:
    // Virtual function: Cho phep class con ghi de
    virtual void tiengKeu() { cout << "Dong vat keu..." << endl; }

    // Virtual funcyion + final: Khong cho class con ghi de
    virtual void diChuyen() final { cout << "Dong vat di chuyen..." << endl; }
};

// Class con 1
class Cho : public DongVat {
   public:
    // Override: Danh dau dang ghi de
    void tiengKeu() override { cout << "Cho: Gau gau!!!" << endl; }
};

// Class con 2
class Meo : public DongVat {
   public:
    void tiengKeu() override { cout << "Meo: meo meo!!!" << endl; }
};

// Final class: khong the ke thua
class ChoCon final : public Cho {
   public:
    void tiengKeu() override { cout << "Cho con: Gau Gau (nho)..." << endl; }
};

int main() {
    cout << "===== KHONG DUNG CON TRO =====" << endl;
    DongVat dv;
    Cho cho;
    Meo meo;

    dv.tiengKeu();
    cho.tiengKeu();
    meo.tiengKeu();

    cout << "===== DUNG CON TRO CLASS CHA =====" << endl;
    DongVat* ptr1 = new Cho();
    DongVat* ptr2 = new Meo();

    ptr1->tiengKeu();
    ptr2->tiengKeu();

    ptr1->diChuyen();

    delete ptr1;
    delete ptr2;

    return 0;
}