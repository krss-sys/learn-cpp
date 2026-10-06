#include <iostream>
#include <list>
using namespace std;

int main() {
    cout << "=== 1. KHOI TAO VA THEM ===" << endl;
    list<int> ls;

    ls.push_back(10);
    ls.push_back(20);
    ls.push_front(5);
    ls.push_front(1);

    cout << "list: ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;

    cout << "size: " << ls.size() << endl;

    cout << "\n=== 2. XOA ===" << endl;
    ls.pop_back();
    ls.pop_front();

    cout << "Sau pop_back va pop_front: ";
    for (int x : ls) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== 3. CHEN VA XOA BAT KI ===" << endl;
    list<int> ls2 = {10, 20, 30, 40, 50};
    auto it = ls2.begin();
    advance(it, 2);

    ls2.insert(it, 99);
    cout << "Sau insert: ";
    for (int x : ls2) {
        cout << x << " ";
    }
    cout << endl;

    ls2.erase(it);
    cout << "Sau erase: ";
    for (int x : ls2) {
        cout << x << " ";
    }
    cout << endl;

    cout << "\n=== 4. DUYET BANG ITERATOR ===" << endl;
    for (auto it2 = ls2.begin(); it2 != ls2.end(); it2++) {
        cout << *it2 << " ";
    }
    cout << endl;

    return 0;
}