#pragma once

#include <memory>
#include "ILanguage.h"
#include "HallOfFame.h"
#include "Game.h"


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
