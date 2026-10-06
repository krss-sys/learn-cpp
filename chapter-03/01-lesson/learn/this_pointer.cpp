#include <iostream>
#include <string>
using namespace std;

class SinhVien {
   private:
    string ten;
    int tuoi;

   public:
    // Constructor khoi tao
    SinhVien(string ten, int tuoi) {
        this->ten = ten;  // Phan biet tham so va thuoc tinh
        this->tuoi = tuoi;
    }

    // Desconstructor
    ~SinhVien() { cout << "Da tu dong giai phong cho: " << ten << endl; }

    // In thong tin
    void xuat() {
        cout << "Ten: " << ten << "; Tuoi: " << tuoi << endl;
        // Co the ghi this -> ten van duoc
    }

    // Tra ve chinh doi tuong
    SinhVien& capNhatTen(string ten) {
        this->ten = ten;
        return *this;
    }

    // In dia chi doi tuong
    void inDiaChi() { cout << "Dia chi cua doi tuong: " << this << endl; }
};

int main() {
    cout << "=== DOI TUONG SV1 ===" << endl;
    SinhVien sv1("kiet", 20);
    sv1.xuat();
    sv1.inDiaChi();

    cout << "\n=== DOI TUONG SV2 ===" << endl;
    SinhVien sv2("Mai", 22);
    sv2.xuat();
    sv2.inDiaChi();

    cout << "\n=== Cap nhat lien tiep ===" << endl;
    sv1.capNhatTen("Tuan").capNhatTen("Anh").xuat();

    return 0;
}