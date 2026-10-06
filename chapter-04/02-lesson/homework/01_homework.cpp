#include <iostream>
#include <list>
using namespace std;

int main() {
    int choice;
    list<string> ds;
    do {
        cout << "===== CHUONG TRINH QUAN LI CONG VIEC =====" << endl;
        cout << "1. Them cong viec vao cuoi\n";
        cout << "2. Them cong viec vao dau\n";
        cout << "3. Xoa cong viec cuoi\n";
        cout << "4. Xoa cong viec dau\n";
        cout << "5. Hien thi\n";
        cout << "6. Thoat\n";

        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string cv;
                while (true) {
                    cout << "Nhap cong viec muon them vao cuoi (nhan 0 de thoat): " << endl;
                    getline(cin, cv);
                    if (cv == "0") {
                        cout << "Da thoat!!!\n";
                        break;
                    } else {
                        ds.push_back(cv);
                        cout << "Da luu cong viec\n";
                        break;
                    }
                }
                break;
            }

            case 2: {
                string cv2;
                while (true) {
                    cout << "Nhap cong viec muon them vao dau (nhan 0 de thoat): " << endl;
                    getline(cin, cv2);
                    if (cv2 == "0") {
                        cout << "Da thoat!!!\n";
                        break;
                    } else {
                        ds.push_front(cv2);
                        cout << "Da luu cong viec\n";
                        break;
                    }
                }
                break;
            }

            case 3: {
                ds.pop_back();
                cout << "Da xoa cong viec cuoi\n";
                break;
            }

            case 4: {
                ds.pop_front();
                cout << "Da xoa cong viec dau\n";
                break;
            }

            case 5: {
                int dem = 1;
                cout << "Hien thi cong viec\n";
                for (auto it = ds.begin(); it != ds.end(); it++) {
                    cout << dem << ". " << *it << endl;
                    dem++;
                }
                cout << endl;
                break;
            }

            case 6: {
                cout << "Thoat chuong trinh\n";
                break;
            }

            default:
                cout << "Nhap sai, Nhap lai\n";
        }
    } while (choice != 6);

    return 0;
}