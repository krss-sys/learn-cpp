#include <iostream>
#include <string>
using namespace std;

class SinhVien {
   private:
    string ten;
    int tuoi;
    float diem;

   public:
    // 1. Constructor mac dinh
    SinhVien() {
        ten = "Chua co ten";
        tuoi = 0;
        diem = 0;
        cout << "Constructor mac dinh chay" << endl;
    }

    // 2. Constructor co tham so
    SinhVien(string t, int tu, float d) : ten(t), tuoi(tu), diem(d) {
        cout << "Constructor co tham so chay" << endl;
    }

    // 3. Destructor
    ~SinhVien() { cout << "Destructor chay cho " << ten << endl; }

    void xuat() { cout << "Ten: " << ten << "; Tuoi: " << tuoi << "; Diem: " << diem << endl; }
};

int main() {
    cout << "=== Tao la sinh vien 1 (Constructor mac dinh) ===" << endl;
    SinhVien sv1;
    sv1.xuat();

    cout << "=== Tao la sinh vien 2 (constructor tham so) ===" << endl;
    SinhVien sv2("kiet", 20, 8.5);
    sv2.xuat();

    cout << "\n=== KET THUC MAIN ===" << endl;
    // Destructor chay tu dong

    return 0;
}