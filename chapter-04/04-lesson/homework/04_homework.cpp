#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50, 60};

    cout << "=== IN DANH SACH BAN DAU ===\n";
    for (const int& x : numbers) cout << "  " << x << ", ";
    cout << "\n";

    cout << "\n=== DAO NGUOC DANH SACH ===\n";
    reverse(numbers.begin(), numbers.end());
    for (const int& x : numbers) cout << "  " << x << ", ";
    cout << endl;

    cout << "\n=== COPY ===\n";
    vector<int> cp(6);
    copy(numbers.begin(), numbers.end(), cp.begin());
    for (const int& x : cp) cout << "  " << x << ", ";
    cout << "\n";

    cout << "\n=== COPY (Vector rong) ===\n";
    vector<int> vtr;
    copy(numbers.begin(), numbers.end(), back_inserter(vtr));
    for (const int& x : vtr) cout << "  " << x << ", ";
    cout << "\n";

    cout << "\n=== DAO NGUOC ===\n";
    reverse(vtr.begin(), vtr.end());
    for (const int& x : vtr) cout << "  " << x << ", ";
    cout << "\n";

    return 0;
}