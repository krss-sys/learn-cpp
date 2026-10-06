#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "=== min_element / max_element voi int ===\n";
    vector<int> v = {5, 2, 8, 1, 9, 3};

    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());

    cout << "Min: " << *minIt << ", Vi tri: " << distance(v.begin(), minIt) << "\n";
    cout << "Max: " << *maxIt << ", Vi tri: " << distance(v.begin(), maxIt) << "\n";

    cout << "\n=== min_max ===\n";
    vector<int> v1 = {4, 99, 8, -4, 9, 3};

    auto [minother, maxother] = minmax_element(v1.begin(), v1.end());
    cout << "Tim dong thoi min, max: " << *minother << ", " << *maxother << "\n";

    cout << "\n=== min, max theo pair ===\n";
    vector<pair<string, int>> ds = {{"An", 20}, {"Binh", 25}, {"Cuong", 22}, {"Dung", 18}};

    auto minAge = min_element(ds.begin(), ds.end(),
                              [](const auto& a, const auto& b) { return a.second < b.second; });

    auto maxAge = max_element(ds.begin(), ds.end(),
                              [](const auto& a, const auto& b) { return a.second > b.second; });

    cout << "Nguoi nho tuoi nhat: " << minAge->first << "-" << minAge->second << "\n";
    cout << "Nguoi lon tuoi nhat: " << maxAge->first << "-" << maxAge->second << "\n";

    cout << "\n=== min_max ===\n";
    vector<pair<string, int>> ds1 = {{"An", 22}, {"Binh", 25}, {"Cuong", 13}, {"Dung", 41}};

    auto result = minmax_element(ds1.begin(), ds1.end(),
                                 [](const auto& a, const auto& b) { return a.second < b.second; });

    cout << "Dua nho va lon tuoi nhat: " << result.first->first << ", " << result.second->first
         << "\n";

    return 0;
}