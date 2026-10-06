#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string ho_ten;
    string tu;
    char ki_tu;
    int dem = 0;
    char c;
    string A(10, '-');

    cout << "Nhap ho va ten: ";
    getline(cin, ho_ten);
    cout << "Ho ten: " << ho_ten << "; So ki tu: " << ho_ten.size() << endl;
    cout << A << endl;

    cout << "Nhap 1 ki tu co trong ten: " << endl;
    cin >> ki_tu;
    ki_tu = tolower(ki_tu);
    for (int i = 0; i < ho_ten.size(); i++) {
        c = tolower(ho_ten[i]);
        if (c == ki_tu) {
            dem++;
        }
    }
    cout << "ki tu: " << ki_tu << " da xuat hien: " << dem << " lan" << endl;
    cout << A << endl;

    cout << "Nhap 1 tu bat ki: " << endl;
    cin >> tu;
    if (ho_ten.find(tu) != string::npos) {
        cout << "CO" << endl;
    } else {
        cout << "KO" << endl;
    }
    cout << A << endl;

    string bakitudau = ho_ten.substr(0, 3);
    for (int e = 0; e < bakitudau.size(); e++) {
        bakitudau[e] = toupper(bakitudau[e]);
    }
    cout << bakitudau << endl;
    return 0;
}