#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    cout << "=== reverse ===\n";
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Truoc: ";
    for (const int& x : v) cout << x << ", ";
    cout << "\n";

    reverse(v.begin(), v.end());
    cout << "Sau reverse: ";
    for (const int& x : v) cout << x << ", ";
    cout << "\n";

    cout << "\n=== copy ===\n";
    vector<int> nguon = {10, 20, 30, 40, 50};
    vector<int> dich(5);
    copy(nguon.begin(), nguon.end(), dich.begin());
    cout << "Dich: ";
    for (const int& x : dich) cout << x << ", ";
    cout << "\n";

    cout << "\n=== copy + back_inserter (vector rong) ===\n";
    vector<int> nguon2 = {100, 200, 300};
    vector<int> dich2;
    copy(nguon2.begin(), nguon2.end(), back_inserter(dich2));
    cout << "Dich2: ";
    for (const int& x : dich2) cout << x << ", ";
    cout << "\n";

    return 0;
}