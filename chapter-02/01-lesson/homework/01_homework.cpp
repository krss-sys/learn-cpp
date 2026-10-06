#include <iostream>
#include <string>
using namespace std;

void inChao(string ten);
int binhPhuong(int x);
double tinhTrungBinh(double a, double b, double c);
void kiemtraChanLE(int n);

int main() {
    cout << "===Goi ham inChao===" << endl;
    string nameuser;
    cout << "Nhap ten cua ban: ";
    cin >> nameuser;
    inChao(nameuser);

    cout << "\n===Goi ham binhPhuong===" << endl;
    int x;
    cout << "Nhap 1 so nguyen: ";
    cin >> x;
    int binhphuong = binhPhuong(x);
    cout << "Binh phuong so ban da chon la: " << binhphuong << endl;

    cout << "\n===Goi ham tinhTrungBinh===" << endl;
    double a, b, c;
    cout << "Nhap 3 so thuc bat ki: ";
    cin >> a >> b >> c;
    double diemtb = tinhTrungBinh(a, b, c);
    cout << "diem trung binh 3 so la: " << diemtb << endl;

    cout << "\n===Goi ham kiemtraChanLe===" << endl;
    int n;
    cout << "nhap so nguyen bat ki: ";
    cin >> n;
    kiemtraChanLE(n);

    return 0;
}

void inChao(string ten) { cout << "Xin chao " << ten << ". Chuc ban ngay moi tot lanh" << endl; }

int binhPhuong(int x) { return x * x; }

double tinhTrungBinh(double a, double b, double c) { return (a + b + c) / 3; }

void kiemtraChanLE(int n) {
    if (n % 2 == 0) {
        cout << "Chan" << endl;
    } else {
        cout << "Le" << endl;
    }
}
