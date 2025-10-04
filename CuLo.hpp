#ifndef CULO_HPP
#define CULO_HPP
#define CULO_RED "\033[31m"
#define CULO_GREEN "\033[32m"
#define CULO_YELLOW "\033[33m"
#define CULO_BLUE "\033[34m"
#define CULO_MAGENTA "\033[35m"
#define CULO_CYAN "\033[36m"
#define CULO_RESET "\033[0m"
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

class Culo {
private: 
static bool Running;
public:
    static void start() {
        Running = true;
    }
    static void stop() {
        Running = false;
    }
    static void lb(const std::vector<std::string>& frames, const std::string& color = "") {
        while (Running) {
            std::cout << "\033[?25l" << std::flush;
        for (const auto& frame : frames) {
            std::cout << color<< frame << CULO_RESET << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            for (size_t i = 0; i < frame.length(); ++i) {
                std::cout << "\b";
            }
            for (size_t i = 0; i < frame.length(); ++i) {
                std::cout << " ";
            }
            for (size_t i = 0; i < frame.length(); ++i) {
                std::cout << "\b";
            }
        }
        std::cout << "\033[?25h" << std::flush;
    }
}
};
bool Culo::Running = false;

#endif