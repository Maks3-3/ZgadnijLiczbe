#pragma once

#include <memory>
#include "Settings.h"
#include "Game.h"


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
