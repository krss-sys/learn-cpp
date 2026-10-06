#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, int>> nhanVien = {
        {"Cuong", 30}, {"An", 25}, {"Binh", 30}, {"An", 22}, {"Cuong", 28}};
    cout << "=== Danh sach nhan vien ===\n";
    for (const auto& p : nhanVien) cout << p.first << ": " << p.second << "\n";
    cout << "\n";

    cout << "\n=== Sap xep ten tang dan ===\n";
    sort(nhanVien.begin(), nhanVien.end(),
         [](const auto& a, const auto b) { return a.first < b.first; });
    for (const auto& p : nhanVien) cout << p.first << ": " << p.second << "\n";

    cout << "\n=== Sap xep tuoi giam dan ===\n";
    sort(nhanVien.begin(), nhanVien.end(),
         [](const auto& a, const auto& b) { return a.second > b.second; });
    for (const auto& p : nhanVien) cout << p.first << ": " << p.second << "\n";

    cout << "\n=== Sap xep stable sort ===\n";
    stable_sort(nhanVien.begin(), nhanVien.end(),
                [](const auto& a, const auto& b) { return a.first < b.first; });
    for (const auto& p : nhanVien) cout << p.first << ": " << p.second << "\n";

    return 0;
}