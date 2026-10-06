#include <iostream>
#include <string>
using namespace std;

class SinhVien {
public:
    //Thuoc tinh
    string ten;
    int tuoi;
    float diem;

    //Phuong thuc 1: In thong tin
    void inThongTin() {
        cout << "Ten: " << ten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Diem: " << diem << endl;
    }

    //Phuong thuc 2: xep loai
    string xeploai() {
        if(diem >= 5) return "Dat";
        return "Rot";
    }

    //Phuong thuc 3: Nhap thong tin tu ban phim
    void nhap() {
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap diem: ";
        cin >> diem;
        cin.ignore();
    }
};

int main(){
    SinhVien sv;

    cout << "=== NHAP THONG TIN SINH VIEN ===" << endl;
    sv.nhap();

    cout << "\n=== THONG TIN SINH VIEN ===" << endl;
    sv.inThongTin();

    cout << "Xep loai: " << sv.xeploai() << endl;

    return 0;
}