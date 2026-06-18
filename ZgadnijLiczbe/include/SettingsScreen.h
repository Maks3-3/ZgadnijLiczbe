#pragma once

#include "Settings.h"
#include "HallOfFame.h"

// Ekran ustawien: zmiana jezyka (PL/EN), przelaczanie pytania o tryb
// zakladu oraz czyszczenie Hall of Fame (z potwierdzeniem). Aktualne
// ustawienia sa wypisywane na nowo przy kazdym przejsciu petli run(),
// dzieki czemu sa zawsze widoczne, takze od razu po zmianie.
class SettingsScreen {
private:
    Settings& settings;
    HallOfFame& hallOfFame;

    void printCurrentSettings() const;
    void changeLanguage();
    void toggleAskBetMode();
    void clearHallOfFameFlow();

public:
    SettingsScreen(Settings& settings, HallOfFame& hallOfFame);

    void run();
};
