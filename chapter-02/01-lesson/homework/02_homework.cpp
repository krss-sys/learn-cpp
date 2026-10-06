#include <iostream>
#include <string>
using namespace std;

void themMuoi(int x);
void gapDoi(double y);
void themChuoi(string s);

int main() {
    int a = 5;
    themMuoi(a);
    cout << "Ngoai main: a = " << a << endl;

    double b = 3.5;
    gapDoi(b);
    cout << "Ngoai main: b = " << b << endl;

    string ten = "Kiet";
    themChuoi(ten);
    cout << "Ngoai main: ten = " << ten << endl;
    return 0;
}

void themMuoi(int x) {
    x += 10;
    cout << "Trong ham: x = " << x << endl;
}

void gapDoi(double y) {
    y = y * 2;
    cout << "Trong ham: y = " << y << endl;
}

void themChuoi(string s) {
    s += " Dep Trai";
    cout << "Trong ham: s = " << s << endl;
}