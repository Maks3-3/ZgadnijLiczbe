#include "NewGamePlusGame.h"
#include "RandomGenerator.h"
#include <iostream>

NewGamePlusGame::NewGamePlusGame(DifficultyLevel difficultyLevel, const ILanguage& language)
    : Game(difficultyLevel, language, Game::NO_LIMIT),
      rerollInterval(RandomGenerator::nextInt(6, 8)) {}

std::string NewGamePlusGame::getModeName() const {
    return language.getText(TextKey::SetupModeNewGamePlusOption);
}

bool NewGamePlusGame::isNewGamePlusMode() const { return true; }

void NewGamePlusGame::onAttemptCompleted(int attemptsSoFar) {
    if (attemptsSoFar % rerollInterval == 0) {
        rerollSecretNumber();
        std::cout << language.getText(TextKey::NewGamePlusRerollMessage) << "\n";
    }
}
