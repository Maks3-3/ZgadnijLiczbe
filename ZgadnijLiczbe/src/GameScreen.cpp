#include "GameScreen.h"
#include "ScoreEntry.h"
#include "InputHelper.h"
#include <iostream>

GameScreen::GameScreen(const ILanguage& language, HallOfFame& hallOfFame)
    : language(language), hallOfFame(hallOfFame) {}

void GameScreen::printWinSummary(const Game& game, bool madeTop5) const {
    std::cout << language.getText(TextKey::WonAttemptsLabel) << game.getAttemptsUsed() << "\n";
    std::cout << language.getText(TextKey::WonTimeLabel) << game.getElapsedSeconds() << "\n";
    if (madeTop5) {
        std::cout << language.getText(TextKey::EnteredHallOfFameMessage) << "\n";
    }
}

void GameScreen::printLossSummary(const Game& game) const {
    std::cout << "\n" << language.getText(TextKey::LostBetMessage) << game.getSecretNumber() << "\n";
}

void GameScreen::run(std::unique_ptr<Game> game) {
    std::cout << "\n=== " << game->getModeName() << " ===\n";

    game->play();
    hallOfFame.incrementGamesPlayed();

    if (game->wasWon()) {
        std::cout << "\n" << language.getText(TextKey::CorrectGuessMessage) << "\n";

        std::string name = InputHelper::readName(
            language.getText(TextKey::EnterNamePrompt),
            language.getText(TextKey::InvalidNameMessage));

        ScoreEntry entry(name, game->getAttemptsUsed(), game->getElapsedSeconds(),
                          game->getDifficultyType(), game->isNewGamePlusMode());
        bool madeTop5 = hallOfFame.addEntry(entry);

        printWinSummary(*game, madeTop5);
    } else {
        printLossSummary(*game);
    }

    InputHelper::waitForEnter(language.getText(TextKey::PressEnterPrompt));
}
