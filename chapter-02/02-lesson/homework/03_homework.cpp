#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {2, 4, 6, 8, 10};
    int* ptr = numbers;

    cout << "=== 1. IN GIA TRI ===" << endl;
    cout << "Cach 1: dung chi so mang: numbers[2] = " << numbers[2] << endl;
    cout << "Cach 2: dung con tro offset: *(ptr + 2) = " << *(ptr + 2) << endl;
    cout << "Cach 3: dung con tro nhu mang: ptr[2]: " << ptr[2] << endl;

    cout << "\n=== 2. DUYET MANG BANG CON TRO ===" << endl;
    cout << "Cach 1: dung ptr + offset: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    cout << "Cach 2: dung con tro truot (bien tam): ";
    int* q = numbers;
    for (int i = 0; i < 5; i++) {
        cout << *q << " ";
        q++;
    }
    cout << endl;

    cout << "\n=== 3. THAY DOI GIA TRI QUA CON TRO ===" << endl;
    ptr[0] = 100;
    ptr[4] = 200;
    int* temp = numbers;
    for (int i = 0; i < 5; i++) {
        cout << *temp << " ";
        temp++;
    }
    cout << endl;

    return 0;
}