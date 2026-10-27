#include <iostream>
#include <memory>
#include <string>

struct SinhVien {
    std::string ten;
    SinhVien(std::string t) : ten(t) {
        std::cout << "[TAO] Sinh Vien " << ten << "\n";
    }
    
    ~SinhVien() {
        std::cout << "[HUY] Sinh Vien " << ten << " (bi xoa khoi bo nho)\n";
    }
};

int main() {
    std::cout << "=== BAT DAU ===\n";

    auto sv1 = std::make_shared<SinhVien>("Kiet");
    std::cout << "Dem: " << sv1.use_count() << "\n";

    {
        auto sv2 = sv1;
        std::cout << "Dem " << sv1.use_count() << "\n";

        auto ham_nhan_ban = [](std::shared_ptr<SinhVien> p) {
            std::cout << "Trong lambda, ten: " << p->ten << "\n";
            std::cout << "Dem trong lambda: " << p.use_count() << "\n";
        };
        ham_nhan_ban(sv1);

        std::cout << "Dem sau lambda: " << sv1.use_count() << "\n";
    }
    std::cout << "Dem sau scope: " << sv1.use_count() << "\n";

    std::cout << "=== KET THUC MAIN ===\n";
    return 0;
}