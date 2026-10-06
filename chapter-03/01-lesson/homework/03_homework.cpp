#include <iostream>
#include <string>
using namespace std;

class Nguoi {
   private:
    int canCuoc;

   protected:
    string hoTen;

   public:
    int tuoi;

    void nhap() {
        cout << "Nhap day du ho va ten: ";
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap CCCD: ";
        cin >> canCuoc;
    }

    void xuat() { cout << "Ho va ten: " << hoTen << ", Tuoi: " << tuoi << endl; }
};

class SinhVien : public Nguoi {
   private:
    int maSo;

   public:
    void nhap() {
        Nguoi ::nhap();
        cout << "Nhap ma so sinh vien: ";
        cin >> maSo;
    }

    void xuat() {
        cout << "Ho va ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "MSSV: " << maSo << endl;
    }
};

int main() {
    SinhVien sv;
    sv.nhap();
    sv.xuat();
    // Thử gán trực tiếp từ main
    // sv.hoTen = "Kiet";          // ❌ Lỗi? (protected)
    // sv.canCuoc = "123";         // ❌ Lỗi? (private)
    // sv.tuoi = 20;               // ✅ Được? (public)
    // sv.maSo = "SV002";          // ❌ Lỗi? (private)

    return 0;
}