#pragma once

#include <memory>
#include "Settings.h"
#include "Game.h"

// Prowadzi uzytkownika przez konfiguracje nowej gry: wybor trybu
// (standard / nowa gra plus), wybor poziomu trudnosci, a dla trybu
// standardowego (jesli ustawienia tego wymagaja) - pytanie o tryb
// zakladu i maksymalna liczbe prob. Na koniec tworzy wlasciwy obiekt
// gry (StandardGame albo NewGamePlusGame) zwracany jako Game* -
// wywolujacy nie musi znac konkretnej klasy.
class GameSetupScreen {
private:
    const Settings& settings;

    bool chooseNewGamePlusMode() const;
    Difficulty chooseDifficulty() const;
    int resolveMaxAttempts() const;

public:
    explicit GameSetupScreen(const Settings& settings);

    std::unique_ptr<Game> run() const;
};
