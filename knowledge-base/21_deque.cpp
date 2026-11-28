#include <deque>
#include <iostream>

int main() {
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);

    std::cout << d[0] << " " << d[1] << " " << d[2] << "\n";
    std::cout << "size = " << d.size() << "\n";

    d.pop_front();
    std::cout << d[0] << " " << d[1] << "\n";

    return 0;
}