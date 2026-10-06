#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> daySo;
    int choice;
    do {
        cout << "===== QUAN LI DANH SACH SO =====" << endl;
        cout << "1. Them so" << endl;
        cout << "2. Xoa so" << endl;
        cout << "3. Chen so" << endl;
        cout << "4. Hien thi" << endl;
        cout << "5. Thoat" << endl;
        cout << "\nLua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "----------1. Them so (nhan 0 de dung)----------" << endl;
                int x;
                while (true) {
                    cout << "Nhap so muon them: ";
                    cin >> x;
                    if (x == 0) {
                        cout << "Da thoat" << endl;
                        break;
                    } else {
                        daySo.push_back(x);
                    }
                }
                break;
            }

            case 2: {
                cout << "----------2. Xoa so (nhan 0 de dung)-----------" << endl;
                int viTri;
                while (true) {
                    cout << "Danh sach so hien tai" << endl;
                    for (int i = 0; i < daySo.size(); i++) {
                        cout << i + 1 << ". " << daySo[i] << endl;
                    }
                    cout << endl;

                    cout << "Nhap vi tri so muon xoa: ";
                    cin >> viTri;
                    if (viTri == 0) {
                        cout << "Da thoat" << endl;
                        break;
                    } else if (viTri > 0 && viTri <= daySo.size()) {
                        daySo.erase(daySo.begin() + (viTri - 1));
                    } else {
                        cout << "Ko hop le" << endl;
                    }
                }
                break;
            }

            case 3: {
                int soMuonThem, viTriChen;
                cout << "----------3. Chen so-----------" << endl;
                cout << "Danh sach hien tai" << endl;
                for (int i = 0; i < daySo.size(); i++) {
                    cout << i + 1 << ". " << daySo[i] << endl;
                }
                cout << "Nhap lan luot vi tri muon chen va so can chen: ";
                cin >> viTriChen >> soMuonThem;
                cin.ignore();
                if (viTriChen > 0 && viTriChen <= daySo.size() + 1) {
                    daySo.insert(daySo.begin() + (viTriChen - 1), soMuonThem);
                    cout << "Da chen thanh cong" << endl;
                } else {
                    cout << "Vi tri chen ko hop le" << endl;
                }
                break;
            }
            case 4: {
                cout << "-----------4. Hien thi----------" << endl;
                for (int x : daySo) {
                    cout << x << " ";
                }
                cout << endl;
                break;
            }

            case 5: {
                cout << "Thoat chuong trinh!!!!" << endl;
                break;
            }
            default:
                cout << "SAI! Nhap lai" << endl;
        }
    } while (choice != 5);

    return 0;
}
