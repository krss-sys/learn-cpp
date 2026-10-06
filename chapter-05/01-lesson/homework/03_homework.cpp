#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main () {
    cout << "=== DUNG DUONG DAN ===\n";
    fs::path myPath = "logs/2026/today";

    cout << "\n=== TAO CHUOI FOLDER ===\n";
    if (fs::create_directories(myPath)) {
        cout << "Tao thanh cong folder " << myPath.filename() << "\n";
    } else {
        cout << "Co san roi\n";
    }

    cout << "\n=== CHECK TON TAI ===\n";
    if (fs::exists(myPath)) {
        cout << "Folder " << myPath.filename() << " ton tai\n";
    } else {
        cout << "Folder khong ton tai\n";
    }

    fs::path parentPath = "logs";
    uintmax_t count = fs::remove_all(parentPath);
    cout << "Da xoa " << count << " file trong " << parentPath.filename() << "\n";

    return 0;
}