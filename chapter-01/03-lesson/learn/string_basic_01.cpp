#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    // Nối
    s += " World";
    cout << s << endl;

    // Lay ki tu
    cout << "Lay ki tu dau tien: " << s[0] << endl;
    cout << "Lay ki tu cuoi: " << s[s.size() - 1] << endl;

    // Do dai
    cout << "Do dai: " << s.size() << endl;

    // Chuoi con
    string sub = s.substr(0, 5);
    cout << "Chuoi con: " << sub << endl;

    int pos = s.find("World");
    if (pos != string::npos) {
        cout << "Da tim thay tai vi tri: " << pos << endl;
    } else {
        cout << "Khong tim thay" << endl;
    }

    // Nhap ca dong
    string nhap;
    cout << "Nhap 1 cau: ";
    getline(cin, nhap);
    cout << "Ban vua nhap: " << nhap << endl;

    return 0;
}