#pragma once

#include "Game.h"

// Tryb "Nowa gra plus". DZIEDZICZY po Game i nadpisuje
// onAttemptCompleted (POLIMORFIZM): co 6, 7 albo 8 strzalow (wybrane
// losowo na starcie rozgrywki) ukryta liczba jest losowana na nowo.
// Tryb zakladu jest dla niego niedostepny (zawsze NO_LIMIT).
class NewGamePlusGame : public Game {
private:
    int rerollInterval;

protected:
    void onAttemptCompleted(int attemptsSoFar) override;

public:
    NewGamePlusGame(DifficultyLevel difficultyLevel, const ILanguage& language);

    std::string getModeName() const override;
    bool isNewGamePlusMode() const override;
};
