#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct SinhVien {
    char ten[50];
    int tuoi;
    double diem;
};

int main() {
    cout << "=== 1. GHI FILE BINARY (write) ===\n";
    ofstream out("data/sinhvien.bin", ios::binary);

    if (!out.is_open()) {
        cout << "Khong the mo file de ghi!!!\n";
        return 1;
    }

    SinhVien sv1 = {"Nguyen Van An", 20, 8.5};
    SinhVien sv2 = {"Tran Thi Bum", 22, 9.0};

    out.write((char*)&sv1, sizeof(sv1));
    out.write((char*)&sv2, sizeof(sv2));
    out.close();
    cout << "Da ghi 2 sinh vien vao file!\n";

    cout << "\n=== 2. DOC FILE BINARY (read) ===\n";
    ifstream in("data/sinhvien.bin", ios::binary);

    if (!in.is_open()) {
        cout << "Khong the mo file de doc!!!\n";
        return 1;
    }

    SinhVien svDoc;
    cout << "Danh sach sinh vien: \n";
    while (in.read((char*)&svDoc, sizeof(svDoc))) {
        cout << "Ten: " << svDoc.ten << ", Tuoi: " << svDoc.tuoi << ", Diem: " << svDoc.diem
             << "\n";
    }

    in.close();

    return 0;
}