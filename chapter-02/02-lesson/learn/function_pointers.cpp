#include <iostream>
using namespace std;

int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }
int nhan(int a, int b) { return a * b; }

void inPhepToan(int x, int y, int (*ptr)(int, int), string ten) {
    cout << ten << " (" << x << " ," << y << ") = " << ptr(x, y) << endl;
}

int main() {
    cout << "=== 1. CON TRO HAM CO BAN ===" << endl;
    int (*ptr)(int, int);

    ptr = &cong;
    cout << "Cong(5, 3): " << ptr(5, 3) << endl;
    ptr = &tru;
    cout << "Tru(5, 3): " << ptr(5, 3) << endl;

    cout << "\n=== 2. TRUYEN CON TRO VAO HAM KHAC ===" << endl;
    inPhepToan(10, 5, cong, "Cong");
    inPhepToan(10, 5, tru, "Tru");
    inPhepToan(10, 5, nhan, "Nhan");

    cout << "\n=== 3. DUNG USING DE DON GIAN HOA ===" << endl;
    using phepToan = int (*)(int, int);
    phepToan ptr2 = &nhan;
    cout << "nhan(4, 7) = " << ptr2(4, 7) << endl;

    return 0;
}
