#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int choice;
    map<string, double> score;
    do {
        cout << "===== QUAN LI DIEM SINH VIEN =====" << endl;
        cout << "   1. Them sinh vien" << endl;
        cout << "   2. Xoa sinh vien" << endl;
        cout << "   3. Tim diem sinh vien" << endl;
        cout << "   4. Hien thi" << endl;
        cout << "   5. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string ten;
                double diem;
                while (true) {
                    cout << "\n***** DANH SACH SINH VIEN (Gõ end để thoát) *****\n";
                    if (score.empty()) {
                        cout << "Danh sach trong\n";
                    } else {
                        for (const auto& m : score) {
                            cout << m.first << ": " << m.second << "\n";
                        }
                    }
                    cout << "Nhap ten sinh vien: ";
                    getline(cin, ten);
                    if (ten == "end" || ten == "END") {
                        cout << "Thoat chuc nang!!!\n";
                        break;
                    }
                    while (true) {
                        cout << "Nhap diem cua " << ten << ": ";
                        cin >> diem;
                        cin.ignore();
                        if (diem >= 0 && diem <= 10) {
                            score[ten] = diem;
                            cout << "---<Da them thanh cong!!!>---\n";
                            break;
                        } else {
                            cout << "Diem khong hop le\n";
                        }
                    }
                }
                break;
            }

            case 2: {
                string ten;
                while (true) {
                    cout << "\n***** DANH SACH SINH VIEN (Gõ end để thoát) *****\n";
                    if (score.empty()) {
                        cout << "Danh sach rong\n";
                        break;
                    } else {
                        for (const auto& m : score) {
                            cout << m.first << ": " << m.second << endl;
                        }

                        cout << "Nhap ten can xoa: ";
                        getline(cin, ten);
                        if (ten == "end" || ten == "END") {
                            cout << "\nThoat chuc nang!!!\n";
                            break;
                        } else if (score.count(ten) != 0) {
                            score.erase(ten);
                        } else {
                            cout << "Khong tim thay sinh vien\n";
                        }
                    }
                }
                break;
            }

            case 3: {
                string ten;
                while (true) {
                    cout << "\n***** TRA CUU DIEM SINH VIEN (nhân end để thoát) *****\n";
                    cout << "Nhap ten sinh vien muon tra diem: ";
                    getline(cin, ten);
                    if (ten == "end" || ten == "END") {
                        cout << "Thoat chuc nang !!!\n";
                        break;
                    } else {
                        auto it = score.find(ten);
                        if (it != score.end()) {
                            cout << (*it).first << ": " << (*it).second << endl;
                        } else {
                            cout << "Khong tim thay ten sinh vien\n";
                        }
                    }
                }
                break;
            }

            case 4: {
                cout << "\n***** HIEN THI DANH SACH SINH VIEN *****\n";
                if (score.empty()) {
                    cout << "Danh sach rong\n";
                } else {
                    for (const auto& m : score) {
                        cout << m.first << ": " << m.second << endl;
                    }
                }
                break;
            }

            case 5: {
                cout << "\nThoat chuong trinh\n";
                break;
            }

            default:
                cout << "Khong hop le, nhap lai!!!\n";
        }

    } while (choice != 5);

    return 0;
}