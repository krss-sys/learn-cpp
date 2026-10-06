#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class KhoHang {
   private:
    unordered_map<string, int> kho;

   public:
    void themSanPham() {
        string tenSp;
        int soLuong;
        while (true) {
            cout << "\n===== Them San Pham (nhan end de thoat)=====\n";
            cout << "\n<<<<<Danh sach san pham hien tai >>>>>\n";
            if (kho.empty()) {
                cout << "~~~~~Danh sach rong~~~~~\n";
            } else {
                for (const auto& p : kho) {
                    cout << p.first << ": " << p.second << endl;
                }
            }
            while (true) {
                cout << "\nNhap ten san pham: ";
                getline(cin, tenSp);
                if (tenSp == "end" || tenSp == "END") {
                    cout << "Da thoat chuc nang!!!\n";
                    return;
                } else {
                    while (true) {
                        cout << "Nhap so luong cua " << tenSp << ": ";
                        cin >> soLuong;
                        cin.ignore(1000, '\n');
                        if (soLuong <= 0) {
                            cout << "Chi so khong hop le, Nhap lai!!!\n";
                        } else {
                            kho[tenSp] += soLuong;
                            cout << "Da them san pham thanh cong vao kho\n";
                            break;
                        }
                    }
                }
            }
        }
    }

    void capNhatSoLuong() {
        string tenSp;
        int soLuong;
        cout << "\n===== Cap Nhat San Pham (Nhan end de thoat) =====\n";
        cout << "\n<<<<<Danh sach san pham hien tai>>>>>\n";
        if (kho.empty()) {
            cout << "~~~~~Danh sach rong~~~~~\n";
            return;
        }
        for (const auto& p : kho) {
            cout << p.first << ": " << p.second << endl;
        }
        cout << "Nhap ten san pham muon cap nhat: ";
        getline(cin, tenSp);
        if (tenSp == "end" || tenSp == "END") {
            cout << "Da thoat chuc nang!!!\n";
            return;  // Cho nay hoi ngu, neu return thi ben duoi ko can else if gi, nhung luoi sua
                     // qua
        }
        if (kho.count(tenSp)) {
            cout << "Da tim thay san pham: " << tenSp << endl;
            while (true) {
                cout << "Nhap so luong muon cap nhat: ";
                cin >> soLuong;
                if (soLuong < 0) {
                    cout << "Chi so khong hop le\n";
                } else {
                    cin.ignore(1000, '\n');
                    kho[tenSp] = soLuong;
                    cout << "Da cap nhat san pham!!!\n";
                    break;
                }
            }
        } else {
            cout << "San Pham khong co trong kho!!!\n";
        }
    }

    void timSanPham() {
        string tenSp;
        while (true) {
            cout << "\n===== Tim San Pham (Nhan end de thoat) =====\n";
            if (kho.empty()) {
                cout << "~~~~~Danh sach kho rong~~~~~\n";
                break;
            }
            cout << "Nhap ten san pham muon tra: ";
            getline(cin, tenSp);
            cout << "\n...\n";
            if (tenSp == "end" || tenSp == "END") {
                cout << "Da thoat chuc nang\n";
                break;
            } else {
                auto it = kho.find(tenSp);
                if (it != kho.end()) {
                    cout << "Tim thay " << it->first << ": " << it->second << endl;
                } else {
                    cout << "Khong tim thay san pham!!!\n";
                }
            }
        }
    }

    void xoaSanPham() {
        string tenSp;
        while (true) {
            cout << "\n===== Xoa San Pham (Nhan end de thoat) =====\n";
            if (kho.empty()) {
                cout << "~~~~~Danh sach kho rong~~~~~\n";
                break;
            }
            cout << "Nhap ten san pham muon xoa: ";
            getline(cin, tenSp);
            cout << "...\n";
            if (tenSp == "end" || tenSp == "END") {
                cout << "Thoat chuc nang\n";
                break;
            } else {
                auto it = kho.find(tenSp);
                if (it != kho.end()) {
                    cout << "Da tim duoc san pham\n";
                    kho.erase(tenSp);
                    cout << "Dang xoa...\n";
                    cout << "Da xoa san pham khoi kho\n";
                } else {
                    cout << "Khong co san pham nhu the trong kho\n";
                }
            }
        }
    }

    void hienThi() {
        cout << "\n===== Danh muc san pham trong kho =====\n";
        if (kho.empty()) {
            cout << "Kho hien tai dang rong\n";
            return;
        }
        for (const auto& p : kho) {
            cout << p.first << ": " << p.second << "\n";
        }
    }
};

void hienThiMenu() {
    cout << "\n###### QUAN LI KHO HANG ######\n";
    cout << "1. Them san pham\n";
    cout << "2. Cap nhat san pham\n";
    cout << "3. Tim san pham\n";
    cout << "4. Xoa san pham\n";
    cout << "5. Hien thi\n";
    cout << "0. Thoat\n";
    cout << "================================\n";
    cout << "Chon chuc nang: ";
}

int main() {
    int choice;
    KhoHang kho;

    while (true) {
        hienThiMenu();
        cin >> choice;
        cin.ignore(1000, '\n');
        if (choice == 0) {
            cout << "Thoat chuong trinh\n";
            break;
        }
        switch (choice) {
            case 1: {
                kho.themSanPham();
                break;
            }

            case 2: {
                kho.capNhatSoLuong();
                break;
            }

            case 3: {
                kho.timSanPham();
                break;
            }

            case 4: {
                kho.xoaSanPham();
                break;
            }

            case 5: {
                kho.hienThi();
                break;
            }

            default:
                cout << "Nhap sai, nhap lai\n";
        }
    }
    return 0;
}
