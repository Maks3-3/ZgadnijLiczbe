#include "EnglishLanguage.h"
#include "RandomGenerator.h"
#include <vector>

LanguageCode EnglishLanguage::getCode() const {
    return LanguageCode::EN;
}

std::string EnglishLanguage::getText(TextKey key) const {
    switch (key) {
        // Welcome screen
        case TextKey::WelcomeTitle: return "Guess the Number";
        case TextKey::MenuNewGame: return "New Game";
        case TextKey::MenuHallOfFame: return "Hall of Fame (TOP5)";
        case TextKey::MenuSettings: return "Settings";
        case TextKey::MenuExit: return "Exit";

        // Generic
        case TextKey::InvalidInput: return "Invalid value, please try again.";
        case TextKey::InvalidNameMessage: return "Name cannot be empty, please try again.";
        case TextKey::ChoicePrompt: return "Your choice: ";
        case TextKey::PressEnterPrompt: return "Press Enter to continue...";
        case TextKey::GoodbyeMessage: return "Thanks for playing. See you next time!";
        case TextKey::YesOption: return "Yes";
        case TextKey::NoOption: return "No";
        case TextKey::OnLabel: return "on";
        case TextKey::OffLabel: return "off";
        case TextKey::BackOption: return "Back to menu";

        // Settings
        case TextKey::SettingsTitle: return "Settings";
        case TextKey::SettingsCurrentLanguageLabel: return "Current language: ";
        case TextKey::SettingsCurrentAskBetLabel: return "Ask about bet mode: ";
        case TextKey::SettingsOptionChangeLanguage: return "Change language";
        case TextKey::SettingsOptionToggleAskBet: return "Toggle bet mode question";
        case TextKey::SettingsOptionClearHallOfFame: return "Clear Hall of Fame records";
        case TextKey::SettingsChooseLanguagePrompt: return "Choose language:";
        case TextKey::SettingsLanguagePLOption: return "Polski";
        case TextKey::SettingsLanguageENOption: return "English";
        case TextKey::SettingsLanguageChanged: return "Language has been changed.";
        case TextKey::SettingsAskBetToggled: return "Setting has been updated.";
        case TextKey::SettingsClearConfirmPrompt:
            return "Are you sure you want to clear all records? This cannot be undone.";
        case TextKey::SettingsCleared: return "The records list has been cleared.";
        case TextKey::SettingsClearCancelled: return "Clearing was cancelled.";

        // Game setup
        case TextKey::SetupChooseModeTitle: return "Choose game mode:";
        case TextKey::SetupModeStandardOption: return "Guess the Number (standard)";
        case TextKey::SetupModeNewGamePlusOption: return "New Game Plus";
        case TextKey::SetupChooseDifficultyTitle: return "Choose difficulty level:";
        case TextKey::DifficultyEasyLabel: return "Easy";
        case TextKey::DifficultyMediumLabel: return "Medium";
        case TextKey::DifficultyHardLabel: return "Hard";
        case TextKey::SetupAskBetModePrompt: return "Do you want to enable bet mode?";
        case TextKey::SetupAskMaxAttemptsPrompt: return "Enter the maximum number of attempts: ";

        // In-game
        case TextKey::AttemptLabel: return "Attempt no.: ";
        case TextKey::GuessPrompt: return "Enter your guess: ";
        case TextKey::CorrectGuessMessage: return "Congratulations! You guessed the correct number!";
        case TextKey::EnterNamePrompt: return "Enter your name: ";
        case TextKey::NewGamePlusRerollMessage:
            return ">>> The number has been re-randomized! Your attempt count keeps going. <<<";
        case TextKey::WonAttemptsLabel: return "Number of attempts: ";
        case TextKey::WonTimeLabel: return "Game duration (s): ";
        case TextKey::EnteredHallOfFameMessage: return "Congratulations! Your score made it into the Hall of Fame!";
        case TextKey::LostBetMessage:
            return "Game over - you exceeded the maximum number of attempts. The number was: ";

        // Hall of Fame
        case TextKey::HallOfFameTitle: return "Hall of Fame";
        case TextKey::HallOfFameEmptyMessage: return "No saved scores for this difficulty level yet.";
        case TextKey::HallOfFameHeaderRank: return "Rank";
        case TextKey::HallOfFameHeaderName: return "Name";
        case TextKey::HallOfFameHeaderAttempts: return "Attempts";
        case TextKey::HallOfFameHeaderTime: return "Time (s)";
        case TextKey::HallOfFameNewGamePlusTag: return "[New Game Plus]";
        case TextKey::HallOfFameSwitchOption: return "Switch difficulty level";
        case TextKey::CurrentDifficultyLabel: return "Difficulty level: ";
    }
    return "";
}

std::string EnglishLanguage::getRandomTooLowMessage() const {
    static const std::vector<std::string> messages = {
        "Too low! Aim higher.",
        "Nope, the number is bigger than that.",
        "Cold... the number is bigger than you think.",
        "Your guess is too small.",
        "Higher, go higher!",
        "Not quite, the number is bigger."
    };
    return messages[RandomGenerator::nextInt(0, static_cast<int>(messages.size()) - 1)];
}

std::string EnglishLanguage::getRandomTooHighMessage() const {
    static const std::vector<std::string> messages = {
        "Too high! Aim lower.",
        "Nope, the number is smaller than that.",
        "Cold... the number is smaller than you think.",
        "Your guess is too big.",
        "Lower, go lower!",
        "Not quite, the number is smaller."
    };
    return messages[RandomGenerator::nextInt(0, static_cast<int>(messages.size()) - 1)];
}
