#include <iostream>
#include <string>
using namespace std;

// 1. Tham tri (copy) -> Cham voi du lieu lon
void inThamTri(string s) { cout << "[Tham tri] " << s << endl; }
// 2. Tham chieu thuong -> Nhanh nhung de bi sua nham
void inThamChieu(string &s) {
    s += " !";
    cout << "[Tham chieu] " << s << endl;
}
// 3. Tham chieu hang -> nhanh, an toan
void inThamChieuHang(const string &s) {
    cout << "[Tham chieu hang] " << s << " (khong the sua)" << endl;
}
// 4. Con tro -> linh hoat nhat
void inConTro(const string *s) {
    if (s != nullptr) {
        cout << "[Con tro] " << *s << endl;
    }
}

int main() {
    string ten = "Kiet Huynh";
    cout << "=== SO SANH 4 CACH TRUYEN ===" << endl;
    inThamTri(ten);
    inThamChieu(ten);
    inThamChieuHang(ten);
    inConTro(&ten);

    cout << "\n=== KIEM TRA BIEN GOC ===" << endl;
    cout << "Ten la: " << ten << endl;

    cout << "\n=== SO SANH TOC DO ===" << endl;
    cout << "Tham tri: copy du lieu (cham)" << endl;
    cout << "Tham chieu: khong copy (nhanh)" << endl;
    cout << "Tham chieu hang: khong copy (nhanh, an toan)" << endl;
    cout << "Con tro: khong copy (nhanh, linh hoat)" << endl;

    return 0;
}