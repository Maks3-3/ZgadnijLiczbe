#pragma once

#include "Settings.h"
#include "HallOfFame.h"

// Glowny kontroler programu: wczytuje stan przy starcie, prowadzi
// petle "ekran powitalny -> akcja -> ekran powitalny" i odpowiada
// za uruchamianie wlasciwych ekranow (Welcome/Settings/HallOfFame/Game).
class Application {
private:
    Settings settings;
    HallOfFame hallOfFame;

public:
    Application();

    void run();
};
