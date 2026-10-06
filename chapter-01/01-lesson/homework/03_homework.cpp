#include <iostream>
using namespace std;

int main() {
    char chu_cai = 'K';
    bool cpp = true;
    char ki_tu;
    bool choice;

    cout << boolalpha;
    cout << "Chu cai dau tien: " << chu_cai << ", Thich C++: " << cpp << endl;
    cout << "Nhap 1 ki tu bat ki: ";
    cin >> ki_tu;
    cout << "Ban vua nhap: " << ki_tu << endl;
    cout << "ban co phai newbie khong?(1= true, 0= false) ";
    cin >> choice;
    cout << "ban la newbie: " << choice;
    return 0;
}