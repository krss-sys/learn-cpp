#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, string> sv(1, "Kiet");
    cout << sv.first << ", " << sv.second << endl;

    auto p = make_pair(3.14, "pi");
    cout << p.first << ", " << p.second << endl;

    return 0;
}