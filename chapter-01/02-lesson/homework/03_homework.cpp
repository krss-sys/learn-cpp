#include <iostream>
using namespace std;

int main() {
    int lua_chon;
    double so;
    int dem = 0;
    double tong = 0;

    do {
        cout << "---MENU---" << endl;
        cout << "1. Nhap so" << endl;
        cout << "2. Xem thong ke" << endl;
        cout << "3. Thoat" << endl;
        cout << "Chon: ";
        cin >> lua_chon;

        switch (lua_chon) {
            case 1:
                cin >> so;
                while (so != 0) {
                    tong = tong + so;
                    dem++;
                    cin >> so;
                }
                break;
            case 2:
                if (dem == 0) {
                    cout << "Chua co so lieu" << endl;
                } else {
                    cout << "Tong: " << tong << endl;
                    cout << "So luong: " << dem << endl;
                    cout << "Trung binh: " << tong / dem << endl;
                }
                break;
            case 3:
                cout << "Thoat" << endl;
                return 0;
            default:
                cout << "Lua chon ko hop le" << endl;
                break;
        }
    } while (true);
    return 0;
}
