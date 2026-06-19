#pragma once

#include "Game.h"

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
