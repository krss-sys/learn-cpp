#include <iostream>
#include <string>
using namespace std;

class Nguoi {
   private:
    string cmnd;  // Thong tin nhay cam

   protected:
    string hoTen;  // Class con dung

   public:
    int tuoi;  // Khong quan trong

    void nhap() {
        cout << "Nhap ho va ten: ";
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap CMND: ";
        getline(cin, cmnd);
    }

    void xuat() {
        cout << "Ho va ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        // cout << "CMND: " << cmnd << endl; (sai, khong truy cap duoc)
    }
};

class SinhVien : public Nguoi {
   private:
    string maSinhVien;

   public:
    void nhap() {
        Nguoi ::nhap();
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSinhVien);
    }

    void xuat() {
        cout << "=== THONG TIN SINH VIEN ===" << endl;
        cout << "Ho va ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        // cout << cmnd (Loi: khong truy cap duoc)
        cout << "Ma SV: " << maSinhVien << endl;
    }
};

int main() {
    SinhVien sv;
    sv.nhap();
    sv.xuat();

    return 0;
}