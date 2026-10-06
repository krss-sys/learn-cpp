#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "=== 1. sort voi lambda ===\n";
    std::vector<int> v = {5, 2, 8, 1, 9, 3};
    std::cout << "  Ban dau: ";
    for (const int& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    std::cout << "  Giam dan: ";
    for (const int& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    sort(v.begin(), v.end(), [](int a, int b) {
        bool aChan = a % 2 == 0;
        bool bChan = b % 2 == 0;
        if (aChan && !bChan) return true;
        if (!aChan && bChan) return false;
        return a < b;
    });

    std::cout << "  Chan truoc, le sau: ";
    for (const int& x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "\n=== 2. find_if voi lambda ===\n";
    std::vector<int> v2 = {1, 3, 5, 6, 7, 9, 10, 12};

    auto it1 = std::find_if(v2.begin(), v2.end(), [](int x) { return x % 2 == 0; });
    if (it1 != v2.end()) {
        std::cout << "-> So chan dau tien: " << *it1 << "\n";
    }

    auto it2 = std::find_if(v2.begin(), v2.end(), [](int x) { return x > 10; });
    if (it2 != v2.end()) {
        std::cout << "-> So lon hon 10 dau tien: " << *it2 << "\n";
    }

    std::cout << "\n=== 3. for_each voi lambda ===\n";
    std::vector<std::string> names = {"An", "Binh", "Cuong", "Dung"};
    std::cout << "  In ten: ";
    std::for_each(names.begin(), names.end(), [](const std::string& s) { std::cout << s << " "; });
    std::cout << "\n";

    std::for_each(names.begin(), names.end(),
                  [](const std::string& s) { std::cout << s << " (" << s.size() << ")\n"; });

    std::cout << "\n=== 4. lambda voi vector<pair> ===\n";
    std::vector<std::pair<std::string, int>> ds = {
        {"An", 20}, {"Binh", 25}, {"Cuong", 22}, {"Dung", 18}};

    std::sort(ds.begin(), ds.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "  Sap xep tuoi tang dan: \n";
    for (const auto& p : ds) {
        std::cout << p.first << " - " << p.second << "\n";
    }

    auto it3 = std::find_if(ds.begin(), ds.end(), [](const auto& p) { return p.second == 22; });
    if (it3 != ds.end()) {
        std::cout << "  Tim thay: " << it3->first << it3->second << "\n";
    }

    return 0;
}