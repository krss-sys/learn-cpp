#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, double>> sv = {
        {"An", 7.5}, {"Binh", 9.0}, {"Cuong", 6.5}, {"Dung", 8.5}, {"An", 5.5}
        // tên trùng để thấy find_if chỉ tìm đầu tiên
    };

    cout << "=== Danh sach sinh vien ===\n";
    for (const auto& p : sv) {
        cout << "   " << p.first << ": " << p.second << "\n";
    }

    string ten;
    cout << "Nhap ten sinh vien can tim: ";
    getline(cin, ten);

    auto it = find_if(sv.begin(), sv.end(), [&ten](const auto& p) { return p.first == ten; });
    if (it != sv.end()) {
        cout << "   Tim thay: " << it->first << " - " << it->second << "\n";
        cout << "   Vi tri: " << distance(sv.begin(), it);
    } else {
        cout << "   Khong tim thay\n";
    }

    cout << "\nTim sinh vien co diem thoa man tren 8:\n";
    auto it2 = find_if(sv.begin(), sv.end(), [](const auto& p) { return p.second >= 8; });
    if (it2 != sv.end()) {
        cout << "   Tim thay: " << it2->first << " - " << it2->second << "\n";
        cout << "   Vi tri: " << distance(sv.begin(), it2) << "\n";
    } else {
        cout << "   Khong tim thay\n";
    }

    return 0;
}