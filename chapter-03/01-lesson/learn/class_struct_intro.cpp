#include <iostream>
#include <string>
using namespace std;

//1. struct - public mac dinh
struct SinhVienStruct {
    string ten;
    int tuoi;
    float diem;
};

//2. class - private mac dinh
class SinhVienClass {
    string ten;
    int tuoi;
    float diem;
};

int main() {
    cout << "=== STRUCT ===" << endl;
    SinhVienStruct sv1;
    sv1.ten = "Kiet";
    sv1.tuoi = 22;
    sv1.diem = 8.25;

    cout << "Ten: " << sv1.ten << endl;
    cout << "Tuoi: " << sv1.tuoi << endl;
    cout << "Diem: " << sv1.diem << endl;

    cout << "\n=== CLASS === (private mac dinh) ===" << endl;
    SinhVienClass sv2;
    //Gia su sv2.ten = "Mai"
    cout << "Khong the truy cap private" << endl;

    return 0;
}
