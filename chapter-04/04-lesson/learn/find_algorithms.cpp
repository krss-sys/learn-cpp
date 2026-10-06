#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "=== find (tim gia tri cu the) ===\n";
    vector<int> v = {10, 20, 30, 40, 50};
    auto it1 = find(v.begin(), v.end(), 30);
    if (it1 != v.end()) {
        cout << "Tim thay 30 tai vi tri: " << distance(v.begin(), it1) << "\n";
    } else {
        cout << "Khong tim thay\n";
    }

    cout << "\n=== find_if (tim so co dieu kien) ===\n";
    vector<int> v2 = {1, 3, 5, 6, 7, 9};
    auto it2 = find_if(v2.begin(), v2.end(), [](int x) { return x % 2 == 0; });
    if (it2 != v2.end()) {
        cout << "So chan dau tien: " << *it2 << "\n";
        cout << "Vi tri: " << distance(v2.begin(), it2) << "\n";
    } else {
        cout << "Khong tim thay\n";
    }

    cout << "\n=== find_if (tim trong vector) ===\n";
    vector<pair<string, int>> ds = {{"An", 20}, {"Binh", 25}, {"Cuong", 22}};

    auto it3 = find_if(ds.begin(), ds.end(), [](const auto& p) { return p.first == "Binh"; });

    if (it3 != ds.end()) {
        cout << "Tim thay: " << it3->first << " - " << it3->second << "\n";
        cout << "Vi tri: " << distance(ds.begin(), it3) << "\n";
    } else {
        cout << "Khong tim thay\n";
    }

    return 0;
}