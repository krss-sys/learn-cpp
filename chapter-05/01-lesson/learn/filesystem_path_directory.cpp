#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    // 1. Dung path xep duong dan
    fs::path myPath = "protect_data";
    myPath /= "2026/logs";

    // 2. Tao chuoi folder
    if (fs::create_directories(myPath)) {
        cout << "Tao chuoi folder thanhf cong!!!\n";
    } else {
        cout << "Folder da co san!!!\n";
    }

    // 3. Check ton tai
    if (fs::exists(myPath)) {
        cout << "Folder " << myPath.filename() << " dang ton tai\n";
    } else {
        cout << "Deo co file nay\n";
    }

    // 4. Xoa can quet
    fs::path parentFolder = "protect_data";
    uintmax_t count = fs::remove_all(parentFolder);
    cout << "Da xoa sach " << count << " file trong " << parentFolder << "\n";

    return 0;
}