#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> danhSach;
    int choice;

    do{
        cout << "===== QUAN LI SINH VIEN =====" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Xoa sinh vien" << endl;
        cout << "3. Sua ten sinh vien" << endl;
        cout << "4. Hien thi danh sach" << endl;
        cout << "5. Thoat" << endl;
        cout << "\nChon: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string ten;
                cout << "Nhap ten sinh vien muon them: ";
                getline(cin, ten);
                danhSach.push_back(ten);
                cout << "Da them sinh vien moi thanh cong !!!" << endl;
                break;
            }

            case 2: {
                int viTriXoa;
                cout << "\nDanh sach sinh vien hien tai: " << endl;
                for (int i = 0; i < danhSach.size(); i++) {
                    cout << i + 1 << ". " << danhSach[i] << endl;
                }
                cout << endl;
                cout << "Nhap vi tri sinh vien muon xoa: ";
                cin >> viTriXoa;
                for (int i = 0; i < danhSach.size(); i++) {
                    if (i + 1 == viTriXoa) {
                        danhSach[i] = danhSach.back();
                        danhSach.pop_back();
                        break;
                    }
                }
                break;
            }

            case 3: {
                string tenSauSua;
                int viTriThay;
                cout << "\nDanh sach sinh vien hien tai: " << endl;
                for (int i = 0; i < danhSach.size(); i++) {
                    cout << i + 1 << ". " << danhSach[i] << endl;
                }
                cout << endl;
                cout << "Nhap vi tri sinh vien muon sua: ";
                cin >> viTriThay;
                cin.ignore();
                cout << "Nhap ten muon sua thanh: ";
                getline(cin, tenSauSua);
                for (int i = 0; i < danhSach.size(); i++) {
                    if (i + 1 == viTriThay) {
                        danhSach[i] = tenSauSua;
                        break;
                    }
                }
                break;
            }

            case 4: {
                cout << "\nDanh sach sinh vien hien tai: " << endl;
                for (const auto x : danhSach) {
                    cout << x << endl;
                }
                break;
            }

            case 5: {
                cout << "Thoat" << endl;
                break;
            }

            default:
                cout << "Chon sai, Nhap lai" << endl;
        }
    } while (choice != 5);

    return 0;
}