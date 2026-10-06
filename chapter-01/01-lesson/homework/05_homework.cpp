#include <iostream>
using namespace std;

main() {
    const double A = 25.0;
    const double B = 4.0;

    cout << "\tKet qua tinh toan" << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A / B = " << A / B << endl;
    int du = static_cast<int>(A) % static_cast<int>(B);
    cout << "A % B = " << du << endl;
    return 0;
}