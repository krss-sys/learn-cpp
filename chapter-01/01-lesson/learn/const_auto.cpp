#include <iostream>
#include <string>
using namespace std;

int main() {
    // const
    const double PI = 3.14159;
    const string TEN = "Newbie";

    // auto
    auto tuoi = 20;       // int
    auto diem = 8.5;      // double
    auto gioitinh = 'M';  // char

    // const + auto
    const auto NAM = 2025;  // const int
    cout << "pi: " << PI << endl;
    cout << "Ten: " << TEN << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "Nam: " << NAM << endl;

    return 0;
}