#include <iostream>
using namespace std;

int main() {
    cout << "=== 1. CON TRO CO BAN ===" << endl;
    int x = 5;
    int* p = &x;

    cout << "Gia tri cua x: " << x << endl;
    cout << "Dia chi cua x: " << &x << endl;
    cout << "Gia tri cua p (Dia chi của x): " << p << endl;
    cout << "Gia tri tai dia chi p dang luu: " << *p << endl;

    cout << "\n=== 2. THAY DOI GIA TRI QUA CON TRO ===" << endl;
    *p = 100;
    cout << "Sau khi *p = 100, x = " << x << endl;
    cout << "Gia tri của *p = " << *p << endl;

    cout << "\n=== 3. NHIEU CON TRO CUNG TRO DEN 1 BIEN ===" << endl;
    int* p2 = &x;
    int* p3 = &x;
    cout << "Gia tri p2: " << *p2 << endl;
    cout << "Gia tri p3: " << *p3 << endl;
    cout << "Dia chi p2 luu: " << p2 << endl;
    cout << "Dia chi p3 luu: " << p3 << endl;
    cout << "-----------------------------------------" << endl;
    *p2 = 200;
    cout << "Sau khi *p2 = 200, x = " << x << endl;
    cout << "Gia tri p2: " << *p2 << endl;
    cout << "Gia tri p3: " << *p3 << endl;
    cout << "Dia chi p2 luu: " << p2 << endl;
    cout << "Dia chi p3 luu: " << p3 << endl;

    cout << "\n=== 4. CON TRO CO THE TRO SANG BIEN KHAC ===" << endl;
    int y = 999;
    cout << "Truoc khi doi: p dang tro den x = " << *p << endl;
    p = &y;
    cout << "Sau khi p = &y thi dia chi ma p luu: " << p << endl;
    cout << "Gia tri mà sau khi giai tham chieu: " << *p << endl;

    cout << "\n=== 5. SO SANH CON TRO VOI BIEN THUONG ===" << endl;
    ;
    int bienThuong = 10;
    int* conTro = &bienThuong;
    cout << "bienThuong = " << bienThuong << endl;
    cout << "conTro = " << conTro << " (Dia Chi)" << endl;
    cout << "*conTro: " << *conTro << " (Gia Tri)" << endl;

    bienThuong = 20;
    cout << "Sau khi sua bienThuong = 20, *conTro = " << *conTro << endl;
    *conTro = 30;
    cout << "Sau khi *conTro = 30, bienThuong = " << bienThuong << endl;

    cout << "\n=== 6. KICH THUOC CON TRO ===" << endl;
    cout << "sizeof(int*): " << sizeof(int*) << " byte" << endl;
    cout << "sizeof(double*): " << sizeof(double*) << " byte" << endl;
    cout << "sizeof(char*): " << sizeof(char*) << " byte" << endl;
    cout << "Tat ca deu cung kich thuoc (8byte tren he 64 bit)" << endl;

    cout << "\n=== 7. CON TRO KHONG TRO VAO DAU (nullptr - SE HOC SAU)===" << endl;
    int* prtNull = nullptr;
    cout << "Con tro nullptr co gia tri: " << prtNull << endl;
    return 0;
}