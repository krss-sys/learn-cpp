#include <iostream>
using namespace std;

int main() {
    cout << "---1. VONG LAP FOR (IN 1..5)---" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "---2. VONG LAP WHILE (IN 1..5)---" << endl;
    int j = 1;
    while (j <= 5) {
        cout << j << " ";
        j++;
    }
    cout << endl << endl;

    cout << "---3. VONG LAP DO-WHILE (IN 1..5)---" << endl;
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 5);
    cout << endl << endl;

    cout << "---4. BREAK (THOAT KHI I== 3)---" << endl;
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            break;
        }
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "---CONTINUE (BO QUA SO CHAN)---" << endl;
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "---DO-WHILE+ BREAK (MENU DON GIAN)---" << endl;
    int lua_chon;
    do {
        cout << "1. TIEP TUC" << endl;
        cout << "2. THOAT" << endl;
        cout << "CHON: ";
        cin >> lua_chon;

        if (lua_chon == 1) {
            cout << "Chay tiep..." << endl;
        } else if (lua_chon == 2) {
            cout << "Thoat" << endl;
            break;
        } else {
            cout << "Sai roi. Chon lai" << endl;
        }
    } while (true);
    return 0;
}