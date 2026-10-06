#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    cout << "=== DUYET BAN ITERATOR ===" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n=== XOA PHAN TU THU 3 (INDEX 2) ===" << endl;
    v.erase(v.begin() + 2);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== CHEN 99 VAO INDEX 1 ===" << endl;
    v.insert(v.begin() + 1, 99);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== CHEN 3 SO 100 VAO INDEX 2 ===" << endl;
    v.insert(v.begin() + 2, 3, 100);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== XOA TU INDEX 1 DEN INDEX 3 ===" << endl;
    v.erase(v.begin() + 1, v.begin() + 4);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}