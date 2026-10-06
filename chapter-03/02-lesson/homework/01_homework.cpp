#include <iostream>
#include <string>
using namespace std;

class HocSinh {
   private:
    string ten;
    int tuoi;

   public:
    // Constructor
    HocSinh(string name, int age) : ten(name), tuoi(age) {}

    // Desconstructor
    ~HocSinh() { cout << "Da desconstructor " << ten << endl; }

    // Copy constructor
    HocSinh(const HocSinh& other) {
        this->ten = other.ten;
        this->tuoi = other.tuoi;
        cout << "Copy thanh cong!" << endl;
    }

    void hienThi() { cout << "Ten nguoi dung: " << ten << " ;Tuoi: " << tuoi << endl; }
};

int main() {
    HocSinh sv1("Truong", 22);
    HocSinh sv2 = sv1;
    HocSinh sv3 = sv1;

    sv1.hienThi();
    sv2.hienThi();
    sv3.hienThi();

    return 0;
}