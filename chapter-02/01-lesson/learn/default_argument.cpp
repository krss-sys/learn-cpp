#include <iostream>
#include <string>
using namespace std;

//========== CU PHAP CO BAN ==========
// Gia tri mac dinh duoc gan tai tham so

void chao(string ten = "Quy Khach") { cout << "Xin chao: " << ten << "!" << endl; }

//========== NHIEU THAM SO MAC DINH =========
// luu y: tham so co default phai dung cuoi
void thongTin(string ten = "Khach", int tuoi = 19, string que = "Ha Noi") {
    cout << "Ten: " << ten << "; Tuoi: " << tuoi << "; Que quan: " << que << endl;
}

//========== KET HOP VOI TAHM TRI ==========
int tinhTong(int a, int b = 20) { return a + b; }

//========== KET HOP VOI IF ==========
double tinhPhiShip(double giaTriDon, double phiShipMacDinh = 30000) {
    if (giaTriDon > 500000) {
        return 0;
    }
    return phiShipMacDinh;
}

//========== KET HOP VOI VONG LAP ==========
void inMenu(int soLanLap = 3) {
    for (int i = 0; i < soLanLap; i++) {
        cout << "1. Choi game\n2. Xem diem\n3. Thoat\n";
    }
}

//========== SO SANH THAM TRI, THAM CHIEU VA DEFAULT ==========
void thamTri(int x) { x = 100; }

void thamChieu(int &x) { x = 100; }

void coDefault(int x, int y = 200) { cout << "x: " << x << "; y: " << y << endl; }

int main() {
    cout << "=== 1. Cach dung co ban ===" << endl;
    chao();
    chao("Tuan");
    chao();

    cout << "=== 2. Nhieu tham so mac dinh ===" << endl;
    thongTin();
    thongTin("Mai");
    thongTin("Mai", 20);
    thongTin("Mai", 20, "HCM");

    cout << "=== 3. Ket hop voi tham tri ===" << endl;
    cout << "tinhTong(5): " << tinhTong(5) << endl;
    cout << "tinhTong(5, 20): " << tinhTong(5, 20) << endl;

    cout << "=== 4. Ket hop voi if ===" << endl;
    cout << "Don 300k, Phi ship: " << tinhPhiShip(300000) << endl;
    cout << "Don 300k, Phi ship 20000: " << tinhPhiShip(300000, 20000) << endl;
    cout << "Don 600K, Phi ship: " << tinhPhiShip(600000) << endl;

    cout << "=== 5. Ket hop voi vong lap ===" << endl;
    cout << "Menu mac dinh (3 lan): " << endl;
    inMenu();
    cout << "\nMenu tuy chinh: " << endl;
    inMenu(10);

    cout << "=== 6. So sanh tham tri - tham chieu - default ===" << endl;
    int a = 10;
    cout << "Truoc thamTri: a = " << a << endl;
    thamTri(a);
    cout << "Sau thamTri: a = " << a << endl;

    thamChieu(a);
    cout << "Sau thamChieu: a = " << a << endl;

    coDefault(5);
    coDefault(5, 100);

    cout << "\n=== 7. Loi thuong gap ===" << endl;
    cout << "Loi 1: tham so co default phai dung cuoi" << endl;
    cout << "Sai: void ham(int x = 10 , int y)" << endl;
    cout << "Loi 2: khong the co default cho tham chieu";

    return 0;
}