#include <chrono>
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    fs::path p = "test";

    if (!fs::exists(p)) {
        cout << "Thu muc test khong ton tai!\n";
        cout << "Tao thu muc test...\n";
        fs::create_directory(p);
        return 1;
    }

    cout << "=== DUYET THU MUC (data) ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        cout << entry.path().filename() << "\n";
    }

    cout << "\n=== THONG TIN CHI TIET ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        if (fs::is_regular_file(entry.path())) {
            cout << "File: " << entry.path().filename() << ", Size: " << fs::file_size(entry.path())
                 << " bytes"
                 << "\n";
        } else if (fs::is_directory(entry.path())) {
            cout << "[THU MUC] " << entry.path().filename() << "\n";
        }
    }

    cout << "\n=== CHI DOC FILE TXT ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        if (entry.path().extension() == ".txt") {
            cout << "File txt: " << entry.path().filename() << "\n";
        }
    }

    return 0;
}