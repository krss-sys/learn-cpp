#include <iostream>
using namespace std;

//=== 1. HAM NHAP MANG DONG (dung new[]) ===
//Muc dich: tao mang voi so phan tu do nguoi dung nhap
int* nhapMang(int &n) {
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    //Cap phat mang dong new[]
    int* arr = new int[n];
    cout << "Nhap " << n << " so" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return arr; //Tra ve con tro dau mang
}

//=== 2. HAM IN MANG (dung con tro + kich thuoc) ===
void inMang( int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//=== 3. HAM CONG DON VAO BIEN DONG (dung new cho bien don) ===
void capNhatTong(int* tongPtr, int giaTri) {
    *tongPtr = *tongPtr + giaTri;
}

//=== 4. HAM NHAN DOI MANG (tao mang moi, copy du lieu) ===
int* nhanDoiMang(int* arr, int n, int &newSize) {
    newSize = n * 2;
    int* newArr = new int[newSize];

    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i]; //copy phan tu cu
    }
    for (int i = n; i < newSize; i++) {
        newArr[i] = 0;
    }
    return newArr;
}

//=== 5. HAM NHAN CON TRO HAM (call back) DE XU LI PHAN TU ===
void duyetMang (int* arr, int n, void (*callback) (int)) {
    for (int i = 0; i < n; i++) {
        callback(arr[i]);
    }
}

//=== 6. HAM CALLBACK (in binh phuong) ===
void inBinhPhuong(int x) {
    cout << x * x << " ";
}
///=== 6. HAM CALLBACK (in lap phuong) ===
void inLapPhuong(int x) {
    cout << x * x * x << " ";
}

//=== MAIN ===
int main() {
    cout << "=== PHAN 1: CAP PHAT BIEN DON (new/ delete) ===" << endl;

    //Cap phat 1 bien dong kieu int, gia tri khoi tao 10
    int* p = new int(10);
    cout << "Gia tri ban dau cua p: " << *p << endl;

    //Thay doi gia tri qua con tro
    *p = 99;
    cout << "Sau khi thay doi: " << *p << endl;

    //Dung ham cap nhat (truyen con tro vao ham)
    capNhatTong(p, 50);
    cout << "Sau khi cong them 50: " << *p << endl;

    //Giai phong bien don
    delete p;
    p = nullptr;  //ko tro vao dau het
    cout << "Da delete va gan nullptr" << endl;

    cout << "\n=== PHAN 2: CAP PHAT MANG DONG (new[]/ delete[]) ===" << endl;
    int n;
    int* arr = nhapMang(n);

    cout << "Mang vua nhap: ";
    inMang(arr, n);

    //Tao mang moi (nhan doi kich thuoc)
    int newSize;
    int* doubleArr = nhanDoiMang(arr, n, newSize);
    cout << "Mang sau khi nhan doi kich thuoc: " ;
    inMang(doubleArr, newSize);

    //Giai phong mang cu va mang moi
    delete[] arr;
    delete[] doubleArr;
    arr = nullptr;
    doubleArr = nullptr;
    cout << "Da delete 2 mang va gan nullptr" << endl;

    cout << "\n=== PHAN 3: KET HOP CON TRO HAM ===" << endl;

    //Tao mang moi de demo callback
    int demoSize = 5;
    int* demoArr = new int[demoSize] {1, 2, 3, 4, 5};
    cout << "Mang goc: ";
    inMang(demoArr, demoSize);

    cout << "Binh phuong tung phan tu: ";
    duyetMang(demoArr, demoSize, inBinhPhuong);
    cout << endl;
    cout << "Lap phuong tung phan tu: ";
    duyetMang(demoArr, demoSize, inLapPhuong);
    cout << endl;
    //Giai phong
    delete[] demoArr;
    demoArr = nullptr;

    cout << " \n=== PHAN 4: TONG KET UNG DUNG ===" << endl;
    cout << "- new/delete: cap nhat va giai phong 1 bien dong" << endl;
    cout << "- new[]/delete[]: cap nhat va giai phong mang dong" << endl;
    cout << "- nullptr: danh dau con tro ko tro vao dau het" << endl;
    cout << "- Ket hop voi ham: truyen con tro, tra ve con tro" << endl;
    cout << "- Ket hop voi con tro ham: callback xu li tung phan tu" << endl;
    cout << "- Memory leak: tranh bang cach delete luon di voi new" << endl;

    return 0;
}