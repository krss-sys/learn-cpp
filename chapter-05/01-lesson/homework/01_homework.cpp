#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SinhVien {
   private:
    vector<pair<string, double>> students;
    string fileName;

   public:
    SinhVien(int n = 0) {
        fileName = "data/sinhvien.txt";
        if (n > 0) students.reserve(n);
    }
    ~SinhVien() { cout << "Da destructor!!!\n"; }

    void nhapSinhVien(int n) {
        string ten;
        double diem;
        cout << "== Nhap thong tin sinh vien ==\n";
        for (int i = 0; i < n; i++) {
            cout << "   Nhap ten sinh vien thu " << i + 1 << ": ";
            getline(cin, ten);
            cout << "   Nhap diem sinh vien thu " << i + 1 << ": ";
            cin >> diem;
            cin.ignore(1000, '\n');
            cout << "\n";
            students.emplace_back(ten, diem);
        }
        cout << "   Nhap lieu thanh cong!!!\n";
    }

    void ghiFile() {
        ofstream out(fileName);
        if (out.is_open()) {
            for (const auto& x : students) {
                out << x.first << ": " << x.second << "\n";
            }
            out.close();
        } else {
            cout << "   LOI: khong the mo file!!!\n";
            return;
        }
    }

    void docFile() {
        ifstream in(fileName);
        students.clear();
        string ten;
        double diem;
        if (in.is_open()) {
            while (getline(in, ten, ':')) {
                in >> diem;
                in.ignore(1000, '\n');
                students.emplace_back(ten, diem);
            }
            in.close();
        } else {
            cout << "   LOI: khong the mo file!!!\n";
            return;
        }
    }

    void hienThi() {
        cout << "== Danh sach sinh vien ==\n";
        if (students.empty()) {
            cout << "   Danh sach rong!!!\n";
            return;
        } else {
            for (const auto& x : students) {
                cout << "   " << x.first << ": " << x.second << "\n";
            }
        }
    }

    void tangDan() {
        if (students.empty()) {
            cout << "   Danh sach rong!!!\n";
            return;
        }
        sort(students.begin(), students.end(),
             [](const auto& a, const auto& b) { return a.second < b.second; });
    }

    void giamDan() {
        if (students.empty()) {
            cout << "   Danh sach rong!!!\n";
            return;
        }
        sort(students.begin(), students.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });
    }
};

int main() {
    int choice, n;
    SinhVien sv;

    do {
        cout << "=============== PHAN MEM QUAN LI SINH VIEN ===============\n";
        cout << "==========================================================\n";
        cout << "1. Luu thong tin sinh vien\n";
        cout << "2. Sap xep theo thanh diem tang dan\n";
        cout << "3. Sap xep theo thang diem giam dan\n";
        cout << "4. Hien thi\n";
        cout << "5. Thoat\n\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1: {
                cout << "###Chuc nang: luu thong tin sinh vien###\n";
                cout << "Nhap so sinh vien: ";
                cin >> n;
                cin.ignore(1000, '\n');
                sv.nhapSinhVien(n);
                sv.ghiFile();
                break;
            }

            case 2: {
                cout << "\n###Chuc nang: Sap xep diem tang dan###\n";
                sv.docFile();
                sv.tangDan();
                sv.hienThi();
                break;
            }

            case 3: {
                cout << "\n###Chuc nang: Sap xep diem giam dan###\n";
                sv.docFile();
                sv.giamDan();
                sv.hienThi();
                break;
            }

            case 4: {
                cout << "###Chuc nang: hien thi###\n";
                sv.docFile();
                sv.hienThi();
                break;
            }

            case 5: {
                cout << "###Chuc nang: thoat###\n";
                break;
            }

            default:
                cout << "Nhap loi, nhap lai\n";
        }
    } while (choice != 5);

    return 0;
}
