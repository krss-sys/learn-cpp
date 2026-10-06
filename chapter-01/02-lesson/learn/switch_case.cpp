#include <cctype>
#include <iostream>

using namespace std;

int main() {
    char grade;
    cout << "Nhap diem chu A,B,C,D,F: ";
    cin >> grade;
    char grade_hoa = toupper(grade);

    switch (grade_hoa) {
        case 'A':
            cout << "Xuat sac";
            break;
        case 'B':
            cout << "Gioi";
            break;
        case 'C':
            cout << "Kha";
            break;
        case 'D':
            cout << "Trung binh";
            break;
        case 'F':
            cout << "Yeu";
            break;
        default:
            cout << "DIem ko hop le";
    }
    return 0;
}