#include <iostream>
#include <string>
using namespace std;

//========== 1. SO SANH THAM TRI VA THAM CHIEU ==========

// Tham tri: Khong thay doi bien goc
void thamTri(int x) {
    x = 100;
    cout << "trong thamTri: x = " << x << endl;
}
// Tham chieu: Co thay doi bien goc
void thamChieu(int &x) {
    x = 100;
    cout << "Trong thamChieu: x = " << x << endl;
}

//========== 2. HAM NHAO DU LIEU ==========
void nhapSo(int &x) {
    cout << "Nhap so: ";
    cin >> x;
}

//========== 3. HAM HOAN DOI (SWAP) ==========
void swapSo(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//========= 4. XU LI CHUOI (TRANH COPY) ==========
void vietHoaDau(string &s) {
    if (s.size() > 0) {
        s[0] = toupper(s[0]);
    }
}

//========== 5. TRA VE NHIEU GIA TRI ==========
void tinhToan(int a, int b, int &tong, int &hieu) {
    tong = a + b;
    hieu = a - b;
}

//========== 6. THAM CHIEU HANG (CONST &) ==========
void inThongTin(const string &s) {
    // chi doc khong sua (nhanh, an toan)
    cout << "Thong tin: " << s << endl;
}

//========== MAIN ==========
int main() {
    cout << "=== 1. So sanh tham tri va tham chieu ===" << endl;
    int a = 5;
    cout << "Truoc khi goi: a = " << a << endl;

    thamTri(a);
    cout << "Sau thamTri: a = " << a << endl;

    thamChieu(a);
    cout << "Sau thamChieu: a = " << a << endl;

    cout << "\n=== 2. Ham nhap du lieu ===" << endl;
    int so;
    nhapSo(so);
    cout << "Da nhap: " << so << endl;

    cout << "\n=== 3. Ham hoan doi ===" << endl;
    int x = 10, y = 20;
    cout << "Truoc khi nhap: x = " << x << ", y = " << y << endl;
    swapSo(x, y);
    cout << "Sau swap: x = " << x << ", y = " << y << endl;

    cout << "\n=== 4. XU li chuoi ===" << endl;
    string ten = "kiet";
    cout << "Truoc: " << ten << endl;
    vietHoaDau(ten);
    cout << "Sau: " << ten << endl;

    cout << "\n=== 5. Tra ve nhieu gia tri ===" << endl;
    int tong, hieu;
    tinhToan(15, 7, tong, hieu);
    cout << "15 + 7 = " << tong << endl;
    cout << "15 - 7 = " << hieu << endl;

    cout << "\n=== 6. Tham chieu hang ===" << endl;
    string msg = "Hello world";
    inThongTin(msg);

    return 0;
}