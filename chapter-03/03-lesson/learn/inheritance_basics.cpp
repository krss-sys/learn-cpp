#include <iostream>
#include <string>
using namespace std;

class DongVat {
   protected:
    string ten;
    int tuoi;

   public:
    DongVat(string name, int age) : ten(name), tuoi(age) {}

    void an() { cout << ten << " dang an..." << endl; }

    void ngu() { cout << ten << " dang ngu..." << endl; }
};

class Cho : public DongVat {
   public:
    Cho(string name, int age) : DongVat(name, age) {}

    void sua() { cout << ten << " : Gau Gau!!!" << endl; }
};

class ChoCon : public Cho {
   public:
    ChoCon(string name, int age) : Cho(name, age) {}

    void diChoi() { cout << ten << " dang di choi..." << endl; }
};

int main() {
    cout << "===== CHO =====" << endl;
    Cho cho1("mickey", 3);
    cho1.an();
    cho1.ngu();
    cho1.sua();

    cout << "\n===== CHO CON =====" << endl;
    ChoCon con("Lucky", 1);
    con.an();
    con.sua();
    con.diChoi();

    return 0;
}