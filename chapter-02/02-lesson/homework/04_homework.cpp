#include <iostream>
using namespace std;

int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }
int nhan(int a, int b) { return a * b; }
int chia(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Loi chia cho 0" << endl;
        return 0;
    }
}

void inPhepToan(int x, int y, int (*ptr)(int, int)) {
    cout << "(" << x << " ," << y << ") = " << ptr(x, y) << endl;
}

void thucHienPhepToan(int x, int y, int (*ptr)(int, int)) {
    cout << "=== THUC HIEN PHEP TOAN ===" << endl;
    cout << "Input: " << x << " ," << y << endl;
    cout << "Output: " << ptr(x, y) << endl;
}

int (*chonPhepToan())(int, int) {
    int choice;
    do {
        cout << "1. Cong" << "\n2. Tru" << "\n3. Nhan" << "\n4. Chia" << "\nChon phep toan (1 - 4)"
             << endl;
        cin >> choice;
        if (choice >= 1 && choice <= 4) {
            break;
        }
        cout << "Nhap sai, nhao lai" << endl;
    } while (true);

    switch (choice) {
        case 1:
            return cong;
        case 2:
            return tru;
        case 3:
            return nhan;
        case 4:
            return chia;
    }
    return 0;
}

int main() {
    int a, b;
    cout << "Nhap a va b: " << endl;
    cin >> a >> b;
    int (*ptr)(int, int) = chonPhepToan();
    inPhepToan(a, b, ptr);
    thucHienPhepToan(a, b, ptr);
    return 0;
}
