#pragma once

#include <memory>
#include "ILanguage.h"
#include "HallOfFame.h"
#include "Game.h"

// Uruchamia juz skonfigurowany obiekt Game (polimorficzne game->play()),
// a po jego zakonczeniu obsluguje wygrana (pytanie o imie, dopisanie do
// Hall of Fame) albo przegrana w trybie zakladu (ujawnienie liczby).
class GameScreen {
private:
    const ILanguage& language;
    HallOfFame& hallOfFame;

    void printWinSummary(const Game& game, bool madeTop5) const;
    void printLossSummary(const Game& game) const;

public:
    GameScreen(const ILanguage& language, HallOfFame& hallOfFame);

    void run(std::unique_ptr<Game> game);
};
