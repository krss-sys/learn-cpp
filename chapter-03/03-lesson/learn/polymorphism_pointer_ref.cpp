#include <iostream>
using namespace std;

class DongVat {
   public:
    virtual void tiengKeu() = 0;
    virtual ~DongVat() {}
};

class Cho : public DongVat {
   public:
    void tiengKeu() override { cout << "Gau gau!!!" << endl; }
};

class Meo : public DongVat {
   public:
    void tiengKeu() override { cout << "Meo meo!!!" << endl; }
};

void inTiengKeu(DongVat& dv) { dv.tiengKeu(); }

int main() {
    cout << "===== DA HINH QUA CON TRO =====" << endl;
    DongVat* ds[2];
    ds[0] = new Cho();
    ds[1] = new Meo();

    for (int i = 0; i < 2; i++) {
        ds[i]->tiengKeu();
    }

    for (int i = 0; i < 2; i++) {
        delete ds[i];
    }

    cout << "\n===== DA HINH QUA THAM CHIEU =====" << endl;
    Cho cho;
    Meo meo;

    inTiengKeu(cho);
    inTiengKeu(meo);

    return 0;
}