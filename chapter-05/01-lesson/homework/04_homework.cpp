#include <chrono>
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    int fileCount = 0;
    uintmax_t fileSize = 0;
    fs::path p = "test";

    if (!fs::exists(p)) {
        cout << "Thu muc khong ton tai\n";
        cout << "Dang tao thu muc...\n";
        fs::create_directory(p);
        return 1;
    } else {
        cout << "Thu muc da co san!\n";
    }

    cout << "=== IN DANH SACH FILE/ FOLDER ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        cout << entry.path().filename() << "\n";
    }

    cout << "\n=== IN DANH SACH FILE TXT ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        if (entry.path().extension() == ".txt") {
            cout << entry.path().filename() << "\n";
        }
    }

    cout << "\n=== IN TONG SO FILE VA KICH THUOC ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        if (fs::is_regular_file(entry.path())) {
            ++fileCount;
            fileSize += fs::file_size(entry.path());
        }
    }
    cout << "Tong so file trong thu muc " << p << ": " << fileCount << "\n";
    cout << "Tong size: " << fileSize << "\n";

    cout << "\n=== IN DANH SACH THU MUC CON ===\n";
    for (const auto& entry : fs::directory_iterator(p)) {
        if (fs::is_directory(entry.path())) {
            cout << entry.path().filename() << "\n";
        }
    }

    return 0;
}