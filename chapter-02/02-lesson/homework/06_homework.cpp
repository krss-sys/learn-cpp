#include <iostream>
#include <string>
using namespace std;

//========== 1. CAC HAM CO BAN ==========
int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }
int nhan(int a, int b) { return a * b; }
int chia(int a, int b) {
    if (b == 0) {
        cout << "Loi: chia cho 0" << endl;
        return 0;
    }
    return a / b;
}

//========== 2. KHAI BAO CON TRO HAM ==========
// Cach 1: khai bao truc tiep
int (*phepTinh)(int, int);
// Cach 2: Dung using
using phepToan = int (*)(int, int);

//========== 3. HAM NHAN CON TRO HAM ==========
void inPhepToan(int x, int y, phepToan ptr, string ten) {
    cout << ten << "(" << x << ", " << y << ") = " << ptr(x, y) << endl;
}

void thucHienPhepToan(int x, int y, phepToan ptr, string ten) {
    cout << "===Thuc hien phep toan===" << endl;
    cout << "Phep toan: " << ten << endl;
    cout << "Input: " << x << ", " << y << endl;
    cout << "Output: " << ptr(x, y) << endl;
}

//========== 4. HAM TRA VE CON TRO HAM ===========
phepToan chonPhepToan(string &tenPhepToan) {
    int choice;
    do {
        cout << "1. Cong" << endl;
        cout << "2. Tru" << endl;
        cout << "3. Nhan" << endl;
        cout << "4. Chia" << endl;
        cout << "Chon phep toan 1-4: ";
        cin >> choice;
        if (choice >= 1 && choice <= 4) {
            break;
        } else {
            cout << "Nhap khong hop le, Nhap lai!!!!" << endl;
        }
    } while (true);

    switch (choice) {
        case 1:
            tenPhepToan = "Cong";
            return cong;
        case 2:
            tenPhepToan = "Tru";
            return tru;
        case 3:
            tenPhepToan = "Nhan";
            return nhan;
        case 4:
            tenPhepToan = "Chia";
            return chia;
        default:
            return nullptr;
    }
}

//========== 5. MAIN ==========
int main() {
    cout << "=== 1. CON TRO HAM CO BAN ===" << endl;
    //   GAN VA GOI QUA CON TRO
    phepToan ptr = cong;
    cout << "ptr dang tro den cong: " << ptr(10, 5) << endl;
    ptr = tru;
    cout << "ptr dang tro den tru: " << ptr(10, 5) << endl;
    ptr = nhan;
    cout << "ptr dang tro den nhan: " << ptr(10, 5) << endl;

    cout << "\n=== 2. TRUYEN CON TRO VAO HAM KHAC ===" << endl;
    inPhepToan(10, 5, cong, "Cong");
    inPhepToan(10, 5, tru, "Tru");
    inPhepToan(10, 5, nhan, "Nhan");
    inPhepToan(10, 5, chia, "Chia");

    cout << "\n=== 3. HAM TRA VE CON TRO HAM ===" << endl;
    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    // CHON PHEP TOAN
    string ten = " ";
    phepToan ptrChon = chonPhepToan(ten);

    thucHienPhepToan(a, b, ptrChon, ten);

    cout << "\n=== 4. UNG DUNG THUC TE ===" << endl;
    cout << "- Truyen ham vao ham khac (callback)" << endl;
    cout << "- Chon ham dong khi chay (menu)" << endl;
    cout << "- Code linh hoat, de mo rong" << endl;

    return 0;
}
