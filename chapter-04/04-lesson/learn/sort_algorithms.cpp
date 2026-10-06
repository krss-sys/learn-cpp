#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "=== Sort tang dan ===\n";
    vector<int> v1 = {5, 2, 8, 1, 9, 3};
    sort(v1.begin(), v1.end());
    for (int x : v1) cout << x << " ";
    cout << endl;

    cout << "\n=== Sort giam dan ===\n";
    vector<int> v2 = {5, 2, 8, 1, 9, 3};
    sort(v2.begin(), v2.end(), greater<int>());
    for (int x : v2) cout << x << " ";
    cout << endl;

    cout << "\n=== Sort giam dan (lambda) ===\n";
    vector<int> v3 = {5, 2, 8, 1, 9, 3};
    sort(v3.begin(), v3.end(), [](int a, int b) { return a > b; });
    for (int x : v3) cout << x << " ";
    cout << endl;

    cout << "\n=== Stable sort ===\n";
    vector<pair<int, string>> sv = {{8, "An"}, {5, "Binh"}, {8, "Cuong"}, {5, "Dung"}};

    stable_sort(sv.begin(), sv.end(),
                [](const auto& a, const auto& b) { return a.first < b.first; });

    for (auto p : sv) cout << p.first << "- " << p.second << "\n";

    return 0;
}