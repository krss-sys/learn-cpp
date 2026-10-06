#include <iostream>
using namespace std;

int main() {
    double A, B;
    cout << "Nhap so thu nhat (A) va so thu hai (B): " << endl;
    cin >> A >> B;
    char phep_toan;
    cout << "Nhap phep toan (+,-,*,/): ";
    cin >> phep_toan;

    switch (phep_toan) {
        case '+':
            cout << "Ket qua: " << A + B << endl;
            break;
        case '-':
            cout << "Ket qua: " << A - B << endl;
            break;
        case '*':
            cout << "Ket qua: " << A * B << endl;
            break;
        case '/':
            if (B == 0) {
                cout << "Khong the thuc hien phep chia cho 0" << endl;
            } else {
                cout << "Ket qua: " << A / B << endl;
            }
            break;
        default:
            cout << "Phep toan khong hop le";
    }
    return 0;
}