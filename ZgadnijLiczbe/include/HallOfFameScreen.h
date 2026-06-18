#pragma once

#include "HallOfFame.h"
#include "ILanguage.h"
#include "Difficulty.h"

// Ekran wynikow: pokazuje TOP5 dla aktualnie wybranego poziomu
// trudnosci i pozwala przelaczac poziomy (Easy -> Medium -> Hard -> Easy).
// Wpisy zdobyte w trybie "Nowa gra plus" sa dodatkowo oznaczone.
class HallOfFameScreen {
private:
    const HallOfFame& hallOfFame;
    const ILanguage& language;
    Difficulty currentDifficulty;

    void printTable() const;

public:
    HallOfFameScreen(const HallOfFame& hallOfFame, const ILanguage& language);

    void run();
};
