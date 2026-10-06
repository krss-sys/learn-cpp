#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct SanPham {
    char maSanPham[20];
    char tenSanPham[50];
    double gia;
};

int main() {
    cout << "=== GHI VAO FILE BINARY ===\n";
    ofstream out("data/sanpham.bin", ios::binary);
    if (!out.is_open()) {
        cout << "Khong the mo file!!!\n";
        return 1;
    }
    SanPham sp1 = {"SP001", "Keo", 5000};
    SanPham sp2 = {"SP002", "Banh", 10000};
    SanPham sp3 = {"SP003", "Sua", 15000};

    out.write((char*)&sp1, sizeof(sp1));
    out.write((char*)&sp2, sizeof(sp2));
    out.write((char*)&sp3, sizeof(sp3));
    out.close();
    cout << "Da ghi 3 san pham vao binary!!!\n";

    cout << "\n=== DOC FILE ===\n";
    ifstream in("data/sanpham.bin", ios::binary);
    if (!in.is_open()) {
        cout << "Khong the mo file!!!\n";
        return 1;
    }
    SanPham spDoc;
    cout << "\n=== DANH SACH SAN PHAM ===\n";
    while (in.read((char*)&spDoc, sizeof(spDoc))) {
        cout << "Ten: " << spDoc.tenSanPham << "; Ma: " << spDoc.maSanPham << "; Gia: " << spDoc.gia
             << "\n";
    }
    in.close();

    return 0;
}