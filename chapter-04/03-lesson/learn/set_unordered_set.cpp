#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    cout << "=== SET (Sap xep khong trung) ===\n";
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(5);

    for (int x : s) cout << x << " ";
    cout << "\n";

    cout << "Count 5: " << s.count(5) << "\n";
    cout << "Count 99: " << s.count(99) << "\n";

    auto it = s.find(10);
    if (it != s.end()) {
        cout << "Tim thay 10\n";
    }

    s.erase(10);
    cout << "Sau khi xoa 10: \n";
    for (int x : s) cout << x << " ";
    cout << "\n";

    cout << "\n=== UNORDERED_SET (Khong sap xep, O(1)) ===\n";
    unordered_set<int> us;
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(5);

    for (int x : us) cout << x << " ";
    cout << "\n";

    return 0;
}