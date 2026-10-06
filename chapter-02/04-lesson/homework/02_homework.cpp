#include <iostream>
using namespace std;

int main() {
    int rows = 2, cols = 3;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }

    int newRows = rows + 1;
    int** newArr = new int*[newRows];
    for (int i = 0; i < rows; i++) {
        newArr[i] = arr[i];
    }
    newArr[rows] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[rows][j] = 99;
    }

    delete[] arr;
    arr = newArr;
    rows = newRows;

    cout << "============================Mang moi===============================" <<  endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
    cout << "\nDa Giai Phong Bo Nho" << endl;

    return 0;
}