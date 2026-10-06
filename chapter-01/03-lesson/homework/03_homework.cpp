#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int arr[MAX];
    int newsl = 0;
    int newarr[MAX];
    int n;

    // Nhap so Phan tu
    cout << "Nhap so phan tu can tinh (toi da 100): ";
    cin >> n;
    if (n < 1 || n > MAX) {
        cout << "Khong hop le" << endl;
    } else {
        cout << "Nhap tung gia tri: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // in ra
    cout << "----IN PHAN TU----" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // tinh tong
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "Tong: " << sum << endl;

    // GTLN, GTNN
    int maxVal = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    cout << "GTLN: " << maxVal << endl;

    int minVal = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << "GTNN: " << minVal << endl;

    // Dem so chan
    int dem = 0;
    cout << "Cac so chan bao gom: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
            dem++;
        }
    }
    if (dem == 0) {
        cout << "Khong co so chan!!!!" << endl;
    }
    cout << "\nTong so chan la: " << dem << endl;

    // Mang so le
    int demsl = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            demsl++;
            newarr[newsl] = arr[i];
            newsl++;
        }
    }
    cout << "So luong so le la: " << demsl << endl;

    // in mang moi
    cout << "Liet ke: ";
    for (int i = 0; i < demsl; i++) {
        cout << newarr[i] << " ";
    }

    return 0;
}