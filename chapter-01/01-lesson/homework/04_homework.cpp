#include <iostream>
#include <string>
using namespace std;

int main() {
    const double PI = 3.14159;
    const string TEN_GAME = "Stardew Valley";
    auto namPhatHanh = 2016;
    auto gia = 15.99;
    auto daMua = true;

    cout << boolalpha;
    cout << "GAME: " << TEN_GAME << endl;
    cout << "Nam phat hanh: " << namPhatHanh << endl;
    cout << "Gia: " << gia << endl;
    cout << "So PI: " << PI << endl;
    cout << "Da mua: " << daMua << endl;
    return 0;
}