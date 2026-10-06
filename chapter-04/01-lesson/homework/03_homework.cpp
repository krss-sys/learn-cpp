#include <iostream>
#include <string>
using namespace std;

int main() {
    string chuoi;
    cout << "Nhap 1 chuoi: ";
    getline(cin, chuoi);

    int pos = chuoi.find("C++");
    if (pos == string::npos) {
        cout << "Khong tim thay C++" << endl;
    } else {
        cout << "Vi tri cua 'C++': " << pos << endl;
    }

    cout << "5 ki tu dau: " << chuoi.substr(0, 5) << endl;
    cout << "5 ki tu cuoi: " << chuoi.substr(chuoi.size() - 5, 5) << endl;

    int pos2 = chuoi.find(' ');
    while (pos2 != string::npos) {
        chuoi.replace(pos2, 1, "_");
        pos2 = chuoi.find(' ', pos2 + 1);
    }
    cout << chuoi << endl;

    return 0;
}