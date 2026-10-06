#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class TuDien {
   private:
    unordered_set<string> ds;

   public:
    void themTu(const string& tu) { ds.insert(tu); }

    bool kiemTraTu(const string& tu) const { return ds.find(tu) != ds.end(); }

    void xoaTu(const string& tu) {
        if (ds.erase(tu) > 0) {
            cout << "Da xoa tu: " << tu << "\n";
        } else {
            cout << "Tu khong ton tai trong tu dien\n";
        }
    }

    void hienThi() const {
        if (ds.empty()) {
            cout << "Danh sach rong\n";
        } else {
            for (auto x : ds) cout << x << "\n";
        }
    }

    void xuatTuDauTien() const {
        if (ds.empty()) {
            cout << "Danh sach rong\n";
        } else {
            auto it = ds.begin();
            cout << "Tu dau tien: " << *it << "\n";
        }
    }
};

int main() {
    TuDien td;
    int choice;
    do {
        cout << "===== TU DIEN =====\n";
        cout << "1. Them tu\n";
        cout << "2. Kiem tra tu\n";
        cout << "3. Xoa tu\n";
        cout << "4. Hien thi\n";
        cout << "5. Xuat tu dau tien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        if (choice == 0) {
            cout << "Thoat chuong trinh...\n";
            break;
        }

        switch (choice) {
            case 1: {
                string tuCanThem;
                while (true) {
                    cout << "***Them tu (nhan end de thoat)***\n";
                    cout << "[Nhap tu can them]: ";
                    getline(cin, tuCanThem);
                    if (tuCanThem == "end" || tuCanThem == "END") {
                        cout << "Thoat chuc nang...\n";
                        break;
                    } else {
                        td.themTu(tuCanThem);
                        cout << "Da them thanh cong\n\n";
                    }
                }
                break;
            }

            case 2: {
                string tuCanKiemTra;
                bool result;
                while (true) {
                    cout << "***Kiem tra tu (nhan end de thoat)***\n";
                    cout << "[Nhap tu can check]: ";
                    getline(cin, tuCanKiemTra);
                    if (tuCanKiemTra == "end" || tuCanKiemTra == "END") {
                        cout << "Thoat chuc nang...\n";
                        break;
                    } else {
                        result = td.kiemTraTu(tuCanKiemTra);
                        cout << boolalpha << result << endl;
                    }
                }
                break;
            }

            case 3: {
                string tuCanXoa;
                cout << "***Xoa tu***\n";
                cout << "[Nhap tu can xoa]: ";
                getline(cin, tuCanXoa);
                td.xoaTu(tuCanXoa);
                break;
            }

            case 4: {
                cout << "***Hien thi***\n";
                td.hienThi();
                break;
            }

            case 5: {
                cout << "***Xuat tu dau***\n";
                td.xuatTuDauTien();
                break;
            }

            default:
                cout << "Nhap ko hop le, nhap lai!!!\n";
        }
    } while (choice != 0);

    return 0;
}