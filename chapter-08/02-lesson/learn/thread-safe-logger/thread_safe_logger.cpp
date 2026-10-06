#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string_view>
#include <thread>

enum class Level { Debug, Info, Warn, Error };

class Logger {
   private:
    static std::mutex g_logMutex;

    static std::string levelToString(Level level) {
        switch (level) {
            case Level::Debug:
                return "[DEBUG]";
            case Level::Info:
                return "[INFO]";
            case Level::Warn:
                return "[WARN]";
            case Level::Error:
                return "[ERROR]";
        }
        return "[?????]";
    }

   public:
    static void log(Level level, std::string_view message) {
        auto now = std::chrono::system_clock::now();
        auto timeT = std::chrono::system_clock::to_time_t(now);
        auto ms =
            std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

        struct tm timeInfo;
        localtime_r(&timeT, &timeInfo);

        std::ostringstream ss;
        ss << "[" << std::put_time(&timeInfo, "%H:%M:%S") << "." << std::setfill('0')
           << std::setw(3) << ms.count() << "] ";
        ss << levelToString(level) << " ";
        ss << "[" << std::this_thread::get_id() << "] ";
        ss << message << "\n";

        std::lock_guard<std::mutex> lock(g_logMutex);
        std::cerr << ss.str();
    }
};

std::mutex Logger::g_logMutex;

void worker(int id) {
    for (int i = 1; i <= 3; i++) {
        Logger::log(Level::Info,
                    "Worker " + std::to_string(id) + " dang chay lan " + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::cout << "=== TEST THREAD-SAFE LOGGER ===\n";
    std::jthread t1(worker, 1);
    std::jthread t2(worker, 2);
    std::jthread t3(worker, 3);

    return 0;
}