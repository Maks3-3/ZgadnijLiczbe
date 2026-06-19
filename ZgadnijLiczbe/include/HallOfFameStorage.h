#pragma once

#include <string>
#include "HallOfFame.h"

// Odpowiada wylacznie za trwaly zapis/odczyt Hall of Fame z pliku na dysku

class HallOfFameStorage {
public:
    HallOfFameStorage() = delete;

    static std::string getFilePath();
    static HallOfFame load();
    static void save(const HallOfFame& hallOfFame);
};
