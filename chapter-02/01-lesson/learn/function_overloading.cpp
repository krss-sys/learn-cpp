#include <iostream>
using namespace std;

// 1. Khac kieu tham so
int tinhTong(int a, int b) {
    cout << "int version: ";
    return a + b;
}

double tinhTong(double a, double b) {
    cout << "double version: ";
    return a + b;
}

// 2. Khac so luong tham so
int tich(int a, int b, int c) {
    cout << "3 Tham so: ";
    return a * b * c;
}
int tich(int a, int b) {
    cout << "2 Tham so: ";
    return a * b;
}

// 3. Khac thu tu tham so
void in(string ten, int tuoi) { cout << "Ten: " << ten << " ;Tuoi: " << tuoi << endl; }
void in(int tuoi, string ten) { cout << "Tuoi: " << tuoi << "; Ten: " << ten << endl; }

int main() {
    cout << "=== 1. Khac kieu tham so ===" << endl;
    cout << tinhTong(5, 3) << endl;
    cout << tinhTong(5.2, 3.5) << endl;

    cout << "\n=== 2. Khac so luong than so ===" << endl;
    cout << tich(2, 3) << endl;
    cout << tich(2, 3, 4) << endl;

    cout << "\n=== 3. Khac thu tu tham so ===" << endl;
    in("Tuan", 20);
    in(20, "tuan");

    return 0;
}