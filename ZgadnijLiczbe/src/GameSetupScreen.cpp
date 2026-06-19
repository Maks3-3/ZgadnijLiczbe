#include "GameSetupScreen.h"
#include "StandardGame.h"
#include "NewGamePlusGame.h"
#include "DifficultyLevel.h"
#include "InputHelper.h"
#include <iostream>

GameSetupScreen::GameSetupScreen(const Settings& settings) : settings(settings) {}

bool GameSetupScreen::chooseNewGamePlusMode() const {
    const ILanguage& lang = settings.getLanguage();
    std::cout << "\n" << lang.getText(TextKey::SetupChooseModeTitle) << "\n";
    std::cout << "1. " << lang.getText(TextKey::SetupModeStandardOption) << "\n";
    std::cout << "2. " << lang.getText(TextKey::SetupModeNewGamePlusOption) << "\n";

    int choice = InputHelper::readIntInRange(
        lang.getText(TextKey::ChoicePrompt), 1, 2, lang.getText(TextKey::InvalidInput));
    return choice == 2;
}

Difficulty GameSetupScreen::chooseDifficulty() const {
    const ILanguage& lang = settings.getLanguage();
    DifficultyLevel easy(Difficulty::Easy);
    DifficultyLevel medium(Difficulty::Medium);
    DifficultyLevel hard(Difficulty::Hard);

    std::cout << "\n" << lang.getText(TextKey::SetupChooseDifficultyTitle) << "\n";
    std::cout << "1. " << lang.getText(easy.getNameKey())
              << " (" << easy.getMin() << "-" << easy.getMax() << ")\n";
    std::cout << "2. " << lang.getText(medium.getNameKey())
              << " (" << medium.getMin() << "-" << medium.getMax() << ")\n";
    std::cout << "3. " << lang.getText(hard.getNameKey())
              << " (" << hard.getMin() << "-" << hard.getMax() << ")\n";

    int choice = InputHelper::readIntInRange(
        lang.getText(TextKey::ChoicePrompt), 1, 3, lang.getText(TextKey::InvalidInput));

    switch (choice) {
        case 1: return Difficulty::Easy;
        case 2: return Difficulty::Medium;
        default: return Difficulty::Hard;
    }
}

int GameSetupScreen::resolveMaxAttempts() const {
    const ILanguage& lang = settings.getLanguage();
    std::cout << "\n" << lang.getText(TextKey::SetupAskBetModePrompt) << "\n";
    std::cout << "1. " << lang.getText(TextKey::YesOption) << "\n";
    std::cout << "2. " << lang.getText(TextKey::NoOption) << "\n";

    int choice = InputHelper::readIntInRange(
        lang.getText(TextKey::ChoicePrompt), 1, 2, lang.getText(TextKey::InvalidInput));

    if (choice == 2) {
        return Game::NO_LIMIT;
    }

    return InputHelper::readIntInRange(
        lang.getText(TextKey::SetupAskMaxAttemptsPrompt), 1, 1000, lang.getText(TextKey::InvalidInput));
}

std::unique_ptr<Game> GameSetupScreen::run() const {
    bool newGamePlus = chooseNewGamePlusMode();
    Difficulty diff = chooseDifficulty();
    DifficultyLevel level(diff);
    const ILanguage& lang = settings.getLanguage();

    if (newGamePlus) {
        return std::make_unique<NewGamePlusGame>(level, lang);
    }

    int maxAttempts = Game::NO_LIMIT;
    if (settings.isAskBetMode()) {
        maxAttempts = resolveMaxAttempts();
    }
    return std::make_unique<StandardGame>(level, lang, maxAttempts);
}
