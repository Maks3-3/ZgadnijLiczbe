#pragma once

#include <string>
#include "Settings.h"

// Odpowiada wylacznie za trwaly zapis/odczyt ustawien z pliku na dysku.
class SettingsStorage {
public:
    SettingsStorage() = delete;

    static std::string getFilePath();
    static Settings load();
    static void save(const Settings& settings);
};
