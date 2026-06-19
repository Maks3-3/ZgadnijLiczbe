#include "WelcomeScreen.h"
#include "InputHelper.h"
#include <iostream>

WelcomeScreen::WelcomeScreen(const ILanguage& language, bool hallOfFameAvailable)
    : language(language), hallOfFameAvailable(hallOfFameAvailable) {}

MenuChoice WelcomeScreen::run() const {
    std::cout << "\n========================================\n";
    std::cout << "   " << language.getText(TextKey::WelcomeTitle) << "\n";
    std::cout << "========================================\n";

    const int newGameOption = 1;
    const int hofOption = hallOfFameAvailable ? 2 : -1;
    const int settingsOption = hallOfFameAvailable ? 3 : 2;
    const int exitOption = hallOfFameAvailable ? 4 : 3;

    std::cout << newGameOption << ". " << language.getText(TextKey::MenuNewGame) << "\n";
    if (hallOfFameAvailable) {
        std::cout << hofOption << ". " << language.getText(TextKey::MenuHallOfFame) << "\n";
    }
    std::cout << settingsOption << ". " << language.getText(TextKey::MenuSettings) << "\n";
    std::cout << exitOption << ". " << language.getText(TextKey::MenuExit) << "\n";

    int choice = InputHelper::readIntInRange(
        language.getText(TextKey::ChoicePrompt),
        1, exitOption,
        language.getText(TextKey::InvalidInput)
    );

    if (choice == newGameOption) {
        return MenuChoice::NewGame;
    }
    if (hallOfFameAvailable && choice == hofOption) {
        return MenuChoice::ShowHallOfFame;
    }
    if (choice == settingsOption) {
        return MenuChoice::ShowSettings;
    }
    return MenuChoice::Exit;
}
