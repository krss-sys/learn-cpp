#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, int>> sp = {
        {"Keo", 5000}, {"Banh", 10000}, {"Sua", 15000}, {"Nuoc", 8000}, {"Keo", 6000}};

    cout << "=== IN DANH SACH BAN DAU ===\n";
    for (const auto& [ten, tuoi] : sp) {
        cout << "   " << ten << "- " << tuoi << "\n";
    }
    cout << endl;

    cout << "\n=== SAP XEP (T CHON STABLE_SORT) ===\n";
    stable_sort(sp.begin(), sp.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first < b.first;
    });
    cout << "   Da sap xep!!!\n";

    cout << "\n=== TIM SAN PHAM THEO TEN ===\n";
    string tenCanTim;
    cout << "   Nhap ten can tim: ";
    getline(cin, tenCanTim);
    bool found = binary_search(
        sp.begin(), sp.end(), make_pair(tenCanTim, 0),
        [](const pair<string, int>& a, const pair<string, int>& b) { return a.first < b.first; });
    cout << "   San pham " << tenCanTim << ": " << (found ? "Yes" : "No") << "\n";

    cout << "\n=== TIM SAN PHAM THEO GIA ===\n";
    int giaCanTim;
    cout << "   Nhap gia san pham can tim: ";
    cin >> giaCanTim;
    cin.ignore(1000, '\n');

    auto it =
        find_if(sp.begin(), sp.end(), [giaCanTim](const auto& p) { return p.second == giaCanTim; });
    if (it != sp.end()) {
        cout << "   Tim thay " << it->first << ", Tai vi tri: " << distance(sp.begin(), it) << "\n";
    } else {
        cout << "   Deo thay\n";
    }

    return 0;
}