#include <iostream>
using namespace std;

// Khai bao ham (prototype)
int tinhTong(int a, int b);
void inChao();

int main() {
    // Goi ham tinhTong
    int x = 10, y = 20;
    int tong = tinhTong(x, y);
    cout << "Tong: " << tong << endl;

    // Goi ham inChao
    inChao();

    return 0;
}

// DInh nghia ham tinhTong
int tinhTong(int a, int b) { return a + b; }

// Dinh nghia ham inChao
void inChao() { cout << "Xin chao!" << endl; }