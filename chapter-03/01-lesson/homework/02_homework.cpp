#include <iostream>
#include <string>
using namespace std;

class ThongTinSach {
   private:
    string tuaSach;
    string tacGia;
    int namXuatBan;
    int soTrang;

   public:
    void nhap() {
        cout << "Nhap ten sach: ";
        getline(cin, tuaSach);
        cout << "Nhap ten tac gia: ";
        getline(cin, tacGia);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap so trang: ";
        cin >> soTrang;
        cin.ignore();
    }

    void xuat() {
        cout << "=== THONG TIN SACH ===" << endl;
        cout << "Ten sach: " << tuaSach << "; Tac gia: " << tacGia << endl;
        cout << "Sach co " << soTrang << " trang; Duoc xuat ban vao nam: " << namXuatBan << endl;
    }

    string loaiSach() {
        if (soTrang > 300) return "Dai";
        return "Ngan";
    }

    string kiemTraSach(string tenTacGia) {
        if (tenTacGia == tacGia) {
            return "Chuan";
        }
        return "Sai roi";
    }

    void capNhatNam(int namMoi) { namXuatBan = namMoi; }
};

int main() {
    ThongTinSach sach;
    string checkTacGia;
    int newyear;

    sach.nhap();
    sach.xuat();
    cout << "Loai sach: " << sach.loaiSach() << endl;
    cout << "Nhap ten tac gia de kiem tra: ";
    getline(cin, checkTacGia);
    checkTacGia = sach.kiemTraSach(checkTacGia);
    cout << checkTacGia << endl;
    cout << "Cap nhat nam moi: ";
    cin >> newyear;
    sach.capNhatNam(newyear);
    sach.xuat();
    return 0;
}