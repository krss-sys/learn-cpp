#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string fullname;
    cout << "Nhap ho va ten: ";
    getline(cin, fullname);

    // Tim ho
    int posFirstSpace = fullname.find(' ');
    string ho = fullname.substr(0, posFirstSpace);

    // Tim ten
    int posLastSpace = fullname.rfind(' ');
    string ten = fullname.substr(posLastSpace + 1);

    // Viet hoa
    char firstChar = ten[0];
    char firstCharUpper = toupper(firstChar);

    cout << "Ho: " << ho << endl;
    cout << "Ten: " << ten << endl;
    cout << "Chu cai: " << firstCharUpper << endl;

    return 0;
}
