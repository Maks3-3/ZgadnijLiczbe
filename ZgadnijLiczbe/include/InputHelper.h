#pragma once

#include <string>

class InputHelper {
public:
    InputHelper() = delete;

    // Wczytuje liczbe calkowita z zakresu [min, max]. Powtarza prompt, dopoki uzytkownik nie wpisze poprawnej wartosci.

    static int readIntInRange(const std::string& prompt, int min, int max, const std::string& invalidMessage);

    // Wczytuje niepuste imie (usuwa biale znaki na krawedziach i znaki ;).
    static std::string readName(const std::string& prompt, const std::string& invalidMessage);

    // Czeka na wcisniecie Enter przez uzytkownika.
    static void waitForEnter(const std::string& message);
};
