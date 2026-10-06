#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

class TaiKhoan {
   private:
    int soDu = 1000;
    std::mutex mtx;

   public:
    TaiKhoan() { std::cout << "Constructor!\n"; }

    ~TaiKhoan() { std::cout << "Destructor!\n"; }

    void unlockSom(std::string ten) {
        std::unique_lock<std::mutex> lock(mtx);
        if (soDu >= 100) {
            soDu -= 100;
            std::cout << ten << " Rut 100, so du con lai " << soDu << "\n";
        }
        lock.unlock();
        std::cout << "Da unlock som\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void deferLock(std::string ten) {
        std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
        std::cout << ten << " dang chuan bi gui...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        lock.lock();
        soDu += 200;
        std::cout << "Gui 200, so du: " << soDu << "\n";
    }

    void tryLock(std::string ten) {
        std::unique_lock<std::mutex> lock(mtx, std::try_to_lock);
        if (lock.owns_lock()) {
            std::cout << ten << " dang co rut 300...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (soDu >= 300) {
                soDu -= 300;
                std::cout << "Da rut 300, so du: " << soDu << "\n";
            } else {
                std::cout << "So du khong du\n";
            }

        } else {
            std::cout << ten << " dang co rut 300...\n";
            std::cout << "Tai khoan dang bi khoa, thu lai sau\n";
        }
    }
};

int main() {
    TaiKhoan tk1;
    std::jthread t1(&TaiKhoan::unlockSom, &tk1, "Thread 1");
    std::jthread t2(&TaiKhoan::deferLock, &tk1, "Thread 2");
    std::jthread t3(&TaiKhoan::tryLock, &tk1, "Thread 3");

    return 0;
}