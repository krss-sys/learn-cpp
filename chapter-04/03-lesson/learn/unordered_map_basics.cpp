#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cout << "===== UNORDERED_MAP =====" << endl;
    unordered_map<string, int> danhBa;

    danhBa["Kiet"] = 111222333;
    danhBa["Mai"] = 222333444;
    danhBa.insert({"Hung", 333444555});
    danhBa.insert(make_pair("An", 444555666));

    cout << "Sdt cua Kiet: " << danhBa["Kiet"] << endl;

    cout << "\nDuyet unordered_map (khong co thu tu): " << endl;
    for (const auto& p : danhBa) {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\nTim key 'An':\n";
    auto it = danhBa.find("An");
    if (it != danhBa.end()) {
        cout << "Tim thay: " << it->first << " -> " << it->second << endl;
    }

    cout << "\nXoa key 'Mai': " << endl;
    danhBa.erase("Mai");
    for (const auto& p : danhBa) {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\nCount key 'Kiet': " << danhBa.count("Kiet") << endl;
    cout << "Cout key 'Mai': " << danhBa.count("Mai") << endl;
    ;

    return 0;
}