#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "=== 1. GHI FILE (ofstream) ===\n";
    ofstream out("data/output.txt");
    
    if (out.is_open()) {
        out << "Dong 1: Hello\n";
        out << "Dong 2: 100, 200, 300\n";
        out.close();
        cout << "Da ghi file thanh cong\n";
    } else {
        cout << "Khong the mo file de ghi!!!\n";
    }
    
    cout << "\n=== 2. DOC FILE (ifstream) ===\n";
    ifstream in ("data/output.txt");

    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            cout << line << "\n";
        }
        in.close();
    } else {
        cout << "Loi: khong the mo file duoc!!!\n";
    }

    cout << "\n=== 3. MO FILE BANG OPNE() / CLOSE() ===\n";
    ofstream file;
    file.open("data/test.txt");

    if (file.is_open()) {
        file << "Mo bang open()\n";
        file.close();
        cout << "Da ghi bang open()\n";
    }

    return 0;
}