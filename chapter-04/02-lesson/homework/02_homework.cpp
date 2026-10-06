#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
    int choice;
    queue<int> hangDoi;
    stack<string> chuoiHanhDong;
    string hanhDong;
    do {
        cout << "=== BAI TAP GIA LAP HANG DOI VA UNDO ===\n";
        cout << "1. Them so vao hang doi\n";
        cout << "2. Lay so ra khoi hang doi\n";
        cout << "3. Xem lich su\n";
        cout << "4. Undo\n";
        cout << "5. Hien thi\n";
        cout << "6. Thoat\n";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "\nThem so vao hang doi (nhan 0 de thoat): ";
                while (true) {
                    int soHangDoi;
                    cin >> soHangDoi;
                    if (soHangDoi == 0) {
                        cout << "Da thoat\n";
                        break;
                    } else {
                        hangDoi.push(soHangDoi);
                        hanhDong = "Them " + to_string(soHangDoi);
                        chuoiHanhDong.push(hanhDong);
                    }
                }
                break;
            }

            case 2: {
                cout << "\nPhan tu dau cua hang doi: " << hangDoi.front() << endl;
                if (chuoiHanhDong.empty()) {
                    cout << "Hang doi bi rong\n";
                } else {
                    hanhDong = "Xoa " + to_string(hangDoi.front());
                    hangDoi.pop();
                    cout << "Da xoa phan tu dau!!!\n";
                    chuoiHanhDong.push(hanhDong);
                }
                break;
            }

            case 3: {
                cout << "\nXem lich su thao tac\n";
                auto temp = chuoiHanhDong;
                while (!temp.empty()) {
                    cout << temp.top() << endl;
                    temp.pop();
                }
                break;
            }

            case 4: {
                cout << "\nXoa hanh dong cuoi stack: \n";
                if (chuoiHanhDong.empty()) {
                    cout <<"Khong co hanh dong de undo\n";
                } else {
                    cout << chuoiHanhDong.top() << endl;
                    chuoiHanhDong.pop();
                    
                }
                break; 
            }

            case 5: {
                if (hangDoi.empty()) {
                    cout << "Hang doi bi rong\n";
                } else {
                    auto temp2 = hangDoi;
                    cout << "\nHien thi: \n";
                    while (!temp2.empty()) {
                        cout << temp2.front() << endl;
                        temp2.pop();
                    }    
                }
                break;
            }

            case 6: {
                cout << "\nThoat!!!\n";
                break;
            }

            default:
                cout << "\nNhap sai, Nhap lai\n";
        }

    } while (choice != 6);

    return 0;
}