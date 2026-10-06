#include <iostream>
#include <string>
using namespace std;

// 1. Tham tri: Khong thay doi bien goc
void thamTri(int x) {
    x = 100;
    cout << "Trong thamTri: x = " << x << endl;
}
// 2. Tham chieu: Co thay doi bien goc
void thamChieu(int &x) {
    x = 100;
    cout << "Trong thamChieu: x = " << x << endl;
}
// 3. Con tro: Co thay doi bien goc, co the nhan nullptr
void conTro(int *x) {
    if (x != nullptr) {
        *x = 200;
        cout << "Trong conTro: x = " << *x << endl;
    }
}
// 4. Tham tri voi du lieu lon (copy ton thoi  gian)
void inChuoiThamTri(string s) { cout << "Tham tri: " << s << endl; }
// 5. Tham chieu voi du lieu lon
void inChuoiThamChieu(string &s) { cout << "Tham chieu: " << s << endl; }

int main() {
    cout << "=== SO SANH 3 CACH ===\n" << endl;

    int a = 5;
    cout << "Gia tri ban dau cua a: " << a << endl;

    thamTri(a);
    cout << "Sau thamTri: a = " << a << " (Khong doi)" << endl;

    thamChieu(a);
    cout << "Sau thamChieu: a = " << a << " (Da doi)" << endl;

    conTro(&a);
    cout << "Sau conTro: a = " << a << " (Da doi)" << endl;

    // test nullptr
    int *p = nullptr;
    conTro(p);

    cout << "\n=== DU LIEU LON (string) ===" << endl;
    string chuoi = "Hello world";
    inChuoiThamTri(chuoi);
    inChuoiThamChieu(chuoi);

    return 0;
}