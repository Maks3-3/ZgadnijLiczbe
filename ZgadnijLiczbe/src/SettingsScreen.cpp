#include "SettingsScreen.h"
#include "InputHelper.h"
#include "SettingsStorage.h"
#include "HallOfFameStorage.h"
#include "LanguageCode.h"
#include <iostream>

SettingsScreen::SettingsScreen(Settings& settings, HallOfFame& hallOfFame)
    : settings(settings), hallOfFame(hallOfFame) {}

void SettingsScreen::printCurrentSettings() const {
    const ILanguage& lang = settings.getLanguage();
    std::cout << "\n--- " << lang.getText(TextKey::SettingsTitle) << " ---\n";

    std::string languageLabel = (settings.getLanguageCode() == LanguageCode::EN)
        ? lang.getText(TextKey::SettingsLanguageENOption)
        : lang.getText(TextKey::SettingsLanguagePLOption);
    std::cout << lang.getText(TextKey::SettingsCurrentLanguageLabel) << languageLabel << "\n";

    std::string betLabel = settings.isAskBetMode()
        ? lang.getText(TextKey::OnLabel)
        : lang.getText(TextKey::OffLabel);
    std::cout << lang.getText(TextKey::SettingsCurrentAskBetLabel) << betLabel << "\n\n";
}

void SettingsScreen::changeLanguage() {
    const ILanguage& lang = settings.getLanguage();
    std::cout << "\n" << lang.getText(TextKey::SettingsChooseLanguagePrompt) << "\n";
    std::cout << "1. " << lang.getText(TextKey::SettingsLanguagePLOption) << "\n";
    std::cout << "2. " << lang.getText(TextKey::SettingsLanguageENOption) << "\n";

    int choice = InputHelper::readIntInRange(
        lang.getText(TextKey::ChoicePrompt), 1, 2, lang.getText(TextKey::InvalidInput));

    LanguageCode newCode = (choice == 2) ? LanguageCode::EN : LanguageCode::PL;
    settings.setLanguage(newCode);
    SettingsStorage::save(settings);

    std::cout << settings.getLanguage().getText(TextKey::SettingsLanguageChanged) << "\n";
}

void SettingsScreen::toggleAskBetMode() {
    const ILanguage& lang = settings.getLanguage();
    settings.setAskBetMode(!settings.isAskBetMode());
    SettingsStorage::save(settings);
    std::cout << lang.getText(TextKey::SettingsAskBetToggled) << "\n";
}

void SettingsScreen::clearHallOfFameFlow() {
    const ILanguage& lang = settings.getLanguage();
    std::cout << "\n" << lang.getText(TextKey::SettingsClearConfirmPrompt) << "\n";
    std::cout << "1. " << lang.getText(TextKey::YesOption) << "\n";
    std::cout << "2. " << lang.getText(TextKey::NoOption) << "\n";

    int choice = InputHelper::readIntInRange(
        lang.getText(TextKey::ChoicePrompt), 1, 2, lang.getText(TextKey::InvalidInput));

    if (choice == 1) {
        hallOfFame.clear();
        HallOfFameStorage::save(hallOfFame);
        std::cout << lang.getText(TextKey::SettingsCleared) << "\n";
    } else {
        std::cout << lang.getText(TextKey::SettingsClearCancelled) << "\n";
    }
}

void SettingsScreen::run() {
    bool back = false;
    while (!back) {
        printCurrentSettings();
        const ILanguage& lang = settings.getLanguage();

        std::cout << "1. " << lang.getText(TextKey::SettingsOptionChangeLanguage) << "\n";
        std::cout << "2. " << lang.getText(TextKey::SettingsOptionToggleAskBet) << "\n";
        std::cout << "3. " << lang.getText(TextKey::SettingsOptionClearHallOfFame) << "\n";
        std::cout << "4. " << lang.getText(TextKey::BackOption) << "\n";

        int choice = InputHelper::readIntInRange(
            lang.getText(TextKey::ChoicePrompt), 1, 4, lang.getText(TextKey::InvalidInput));

        switch (choice) {
            case 1: changeLanguage(); break;
            case 2: toggleAskBetMode(); break;
            case 3: clearHallOfFameFlow(); break;
            case 4: back = true; break;
        }
    }
}
