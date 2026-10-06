#include <iostream>
using namespace std;

class DiemSo {
   private:
    int* diem;
    int soLuong;

   public:
    // Constructor mac dinh
    DiemSo() {
        soLuong = 0;
        diem = nullptr;
        cout << "Khoi tao constructor mac dinh" << endl;
    }

    // Constructor
    DiemSo(int n) {
        soLuong = n;
        diem = new int[soLuong];
        cout << "Da hoan thanh cap phat dong!!!" << endl;
        cout << "Nhap " << n << " diem: ";
        for (int i = 0; i < soLuong; i++) {
            cin >> diem[i];
        }
    }

    // Copy constructor
    DiemSo(const DiemSo& other) {
        this->soLuong = other.soLuong;
        this->diem = new int[soLuong];
        cout << "\nTien hanh copy mang" << endl;
        for (int i = 0; i < soLuong; i++) {
            this->diem[i] = other.diem[i];
        }
        cout << "Copy constructor dang chay!!!" << endl;
    }

    // Assigment operator
    DiemSo& operator=(const DiemSo& other) {
        if (this != &other) {
            delete[] this->diem;
            this->soLuong = other.soLuong;
            this->diem = new int[this->soLuong];
            for (int i = 0; i < soLuong; i++) {
                this->diem[i] = other.diem[i];
            }
            cout << "assigment dang chay!!!" << endl;
        }
        return *this;
    }

    // Destructor
    ~DiemSo() {
        delete[] diem;
        cout << "Destructor dang chay!!!" << endl;
    }

    void hienThi() {
        cout << "=== DANH SACH DIEM ===" << endl;
        for (int i = 0; i < soLuong; i++) {
            cout << diem[i] << " ";
        }
        cout << endl;
    }

    void tinhTrungBinh() {
        double tong = 0;
        double trungBinh;
        for (int i = 0; i < soLuong; i++) {
            tong += diem[i];
        }
        trungBinh = tong / soLuong;
        cout << "Diem trung binh day diem: " << trungBinh << " diem" << endl;
    }

    void setDiem(int i, int giaTri) {
        if (i >= 0 && i < soLuong) {
            diem[i] = giaTri;
        } else {
            cout << "Khong hop le" << endl;
        }
    }
};

int main() {
    cout << "=== KHOI TAO MANG1 ===" << endl;
    int soLuongDiem;
    cout << "Nhap so luong diem: ";
    cin >> soLuongDiem;
    DiemSo diem1(soLuongDiem);
    diem1.hienThi();

    cout << "=== KHOI TAO MANG2 ===" << endl;
    DiemSo diem2;
    diem2 = diem1;
    diem2.hienThi();

    cout << "=== THAY DOI DIEM ===" << endl;
    diem2.setDiem(0, 10);
    diem1.hienThi();
    diem2.hienThi();

    cout << "=== TINH TRUNG BINH ===" << endl;
    diem1.tinhTrungBinh();
    diem2.tinhTrungBinh();

    return 0;
}