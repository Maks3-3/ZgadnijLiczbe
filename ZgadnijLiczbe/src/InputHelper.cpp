#include "InputHelper.h"
#include <iostream>
#include <cstdlib>

namespace {

std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

std::string removeSemicolons(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        if (c != ';') {
            result += c;
        }
    }
    return result;
}

// Jesli wejscie sie skoncza (np. brak interakcji / przekierowane EOF),
// program konczy sie czysto, zamiast wpadac w nieprzewidywalna petle.
[[noreturn]] void exitOnEof() {
    std::cout << "\n";
    std::exit(0);
}

} // namespace

int InputHelper::readIntInRange(const std::string& prompt, int min, int max, const std::string& invalidMessage) {
    while (true) {
        std::cout << prompt << std::flush;
        std::string line;
        if (!std::getline(std::cin, line)) {
            exitOnEof();
        }
        std::string trimmed = trim(line);
        if (trimmed.empty()) {
            std::cout << invalidMessage << "\n";
            continue;
        }
        try {
            size_t pos = 0;
            int value = std::stoi(trimmed, &pos);
            if (pos != trimmed.size()) {
                std::cout << invalidMessage << "\n";
                continue;
            }
            if (value < min || value > max) {
                std::cout << invalidMessage << "\n";
                continue;
            }
            return value;
        } catch (...) {
            std::cout << invalidMessage << "\n";
        }
    }
}

std::string InputHelper::readName(const std::string& prompt, const std::string& invalidMessage) {
    const size_t MAX_NAME_LENGTH = 20;
    while (true) {
        std::cout << prompt << std::flush;
        std::string line;
        if (!std::getline(std::cin, line)) {
            exitOnEof();
        }
        std::string cleaned = trim(removeSemicolons(line));
        if (cleaned.empty()) {
            std::cout << invalidMessage << "\n";
            continue;
        }
        if (cleaned.size() > MAX_NAME_LENGTH) {
            cleaned = cleaned.substr(0, MAX_NAME_LENGTH);
        }
        return cleaned;
    }
}

void InputHelper::waitForEnter(const std::string& message) {
    std::cout << message << std::flush;
    std::string dummy;
    if (!std::getline(std::cin, dummy)) {
        exitOnEof();
    }
}
