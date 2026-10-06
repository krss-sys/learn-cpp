#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "=== 1. find() ===" << endl;
    string s = "Hello World";
    int pos = s.find("World");
    cout << "Vi tri cua World: " << pos << endl;

    int pos2 = s.find("abc");
    if (pos2 == string::npos) {
        cout << "Khong tim thay 'abc'" << endl;
    }

    cout << "\n=== 2. substr() ===" << endl;
    string sub1 = s.substr(0, 5);
    string sub2 = s.substr(6, 5);
    cout << "substr(0, 5): " << sub1 << endl;
    cout << "substr(6, 5): " << sub2 << endl;
    cout << "substr(6): " << s.substr(6) << endl;

    cout << "\n=== 3. replace() ===" << endl;
    string s2 = "Hello World";
    s2.replace(6, 5, "C++");
    cout << "replace(6, 5, 'C++'): " << s2 << endl;

    cout << "\n=== 4. c_str() ===" << endl;
    string s3 = "C++ Programming";
    const char* cstr = s3.c_str();
    cout << "c_str(): " << cstr << endl;

    return 0;
}