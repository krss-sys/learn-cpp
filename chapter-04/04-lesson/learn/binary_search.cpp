#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "=== binary_search voi so ===\n";
    vector<int> v = {5, 2, 8, 1, 9, 3};
    sort(v.begin(), v.end());

    int soCanTim = 5;
    if (binary_search(v.begin(), v.end(), soCanTim)) {
        cout << "Tim thay " << soCanTim << "\n";
    } else {
        cout << "Khong tim thay " << soCanTim << "\n";
    }

    cout << "\n=== binary_search voi pair (ten + tuoi) ===\n";
    vector<pair<string, int>> ds = {
        {"An", 20},
        {"Binh", 25},
        {"Cuong", 22}
    };

    sort(ds.begin(), ds.end());
    string tenCanTim = "Binh";
    bool found = binary_search(ds.begin(), ds.end(), make_pair(tenCanTim, 25));
    cout << "Tim thay " << tenCanTim << "? " << (found ? "Co" : "Khong") << endl;

    return 0;
}