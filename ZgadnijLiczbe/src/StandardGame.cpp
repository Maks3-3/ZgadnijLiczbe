#include "StandardGame.h"

StandardGame::StandardGame(DifficultyLevel difficultyLevel, const ILanguage& language, int maxAttempts)
    : Game(difficultyLevel, language, maxAttempts) {}

std::string StandardGame::getModeName() const {
    return language.getText(TextKey::SetupModeStandardOption);
}
