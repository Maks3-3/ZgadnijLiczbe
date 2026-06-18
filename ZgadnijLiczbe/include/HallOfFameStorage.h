#pragma once

#include <string>
#include "HallOfFame.h"

// Odpowiada wylacznie za trwaly zapis/odczyt Hall of Fame z pliku na
// dysku. Oddzielenie tej odpowiedzialnosci od klasy HallOfFame to
// przyklad podzialu na osobne, jednoznaczne funkcjonalnosci.
class HallOfFameStorage {
public:
    HallOfFameStorage() = delete;

    static std::string getFilePath();
    static HallOfFame load();
    static void save(const HallOfFame& hallOfFame);
};
