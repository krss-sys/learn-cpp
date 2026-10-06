#include <iostream>
using namespace std;

void themMuoi(int x);

int main() {
    int a = 5;
    cout << "Gia tri cua a khi chua goi ham themMuoi: " << a << endl;

    themMuoi(a);
    cout << "Sau khi goi ham a la: " << a << endl;
    return 0;
}

void themMuoi(int x) {
    x = 10;
    cout << "Gia tri trong ham: " << x << endl;
}
