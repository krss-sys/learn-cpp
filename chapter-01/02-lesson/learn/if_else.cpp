#include <iostream>
using namespace std;

int main() {
    int so;
    cout << "Nhap 1 so nguyen: " << endl;
    cin >> so;

    if (so > 0) {
        cout << "SO DUONG" << endl;
    } else if (so < 0) {
        cout << "SO AM" << endl;
    } else {
        cout << "SO KHONG" << endl;
    }
    return 0;
}