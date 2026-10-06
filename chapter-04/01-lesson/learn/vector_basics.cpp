#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "=== KHOI TAO VECTOR ==="<< endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<string> v2(3, "Hello");

    cout << "v1: ";
    for (const auto &x : v1) {
        cout << x << " ";
    }
    cout << endl;

    cout << "v2: ";
    for (const auto &x : v2) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== THEM / XOA PHAN TU ===" << endl;
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "vector: ";
    for (const auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "Sau pop_back(): ";
    for (const auto & x : v) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== TRUY CAP ===" << endl;
    cout << "front(): " << v.front() << endl;
    cout << "back(): " << v.back() << endl;
    cout << "v[1]: " << v[1] << endl;
    cout << "size(): " << v.size() << endl;

    cout << "\n=== XOA TOAN BO ===" << endl;
    v.clear();
    cout << "Sau clear(), size: " << v.size() << endl;
    cout << "empty(): " << (v.empty() ? "true" : "false") << endl;

    return 0;
}