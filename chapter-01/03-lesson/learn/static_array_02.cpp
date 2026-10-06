#include <iostream>
using namespace std;

int main() {
    // Du lieu co dinh
    int score[5] = {8, 5, 9, 7, 6};
    // Tinh tong
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += score[i];
    }
    cout << "Tong cac phan tu: " << sum << endl;

    // Tim so lon nhat
    int maxVal = score[0];
    for (int i = 0; i < 5; i++) {
        if (score[i] > maxVal) {
            maxVal = score[i];
        }
    }
    cout << "So lon nhat la: " << maxVal << endl;

    // Tim so nho nhat
    int minVal = score[0];
    for (int i = 0; i < 5; i++) {
        if (score[i] < minVal) {
            minVal = score[i];
        }
    }
    cout << "So be nhat la: " << minVal << endl;

    // Dem so chan
    int evencount = 0;
    for (int i = 0; i < 5; i++) {
        if (score[i] % 2 == 0) {
            evencount++;
        }
    }
    cout << "SO luong so chan la: " << evencount << endl;
    // In ra so chan
    cout << "Cac so chan la: ";
    for (int i = 0; i < 5; i++) {
        if (score[i] % 2 == 0) {
            cout << score[i] << " ";
        }
    }
    cout << endl;

    return 0;
}