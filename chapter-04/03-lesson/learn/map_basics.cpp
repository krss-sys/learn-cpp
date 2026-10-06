#include <iostream>
#include <map>
using namespace std;

int main() {
    cout << "=== 1. THEM VA TRUY CAP ===" << endl;
    map<string, int> danhBa;
    danhBa["Kiet"] = 111222333;
    danhBa.insert(make_pair("Mai", 222333444));
    danhBa["Tuan"] = 333444555;
    danhBa.insert({"An", 111111111});

    cout << "Sdt cua Kiet: " << danhBa["Kiet"] << endl;
    cout << "Sdt cua Mai: " << danhBa["Mai"] << endl;

    cout << "\n=== 2. DUYET MAP ===" << endl;
    for (const auto& p : danhBa) {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\n=== 3. TIM KEY ===" << endl;
    string key = "Tuan";
    auto it = danhBa.find(key);
    if (it != danhBa.end()) {
        cout << "Tim thay: " << (*it).first << " -> " << (*it).second << endl;
    } else {
        cout << "Khong tim thay key: " << key << endl;
    }

    cout << "\n=== 4. XOA THEO KEY ===" << endl;
    danhBa.erase("Mai");
    cout << "Sau khi xoa Mai: " << endl;
    for (const auto& p : danhBa) {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\n=== 5. COUT ===" << endl;
    cout << "Co key Kiet? " << danhBa.count("Kiet") << endl;
    cout << "Co key Mai? " << danhBa.count("Mai") << endl;

    return 0;
}