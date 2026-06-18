#include "HallOfFameScreen.h"
#include "DifficultyLevel.h"
#include "ScoreEntry.h"
#include "InputHelper.h"
#include <iostream>
#include <iomanip>
#include <vector>

HallOfFameScreen::HallOfFameScreen(const HallOfFame& hallOfFame, const ILanguage& language)
    : hallOfFame(hallOfFame), language(language), currentDifficulty(Difficulty::Easy) {}

void HallOfFameScreen::printTable() const {
    DifficultyLevel level(currentDifficulty);

    std::cout << "\n========================================\n";
    std::cout << "   " << language.getText(TextKey::HallOfFameTitle) << "\n";
    std::cout << "========================================\n";
    std::cout << language.getText(TextKey::CurrentDifficultyLabel)
              << language.getText(level.getNameKey())
              << " (" << level.getMin() << "-" << level.getMax() << ")\n\n";

    const std::vector<ScoreEntry>& top = hallOfFame.getTop(currentDifficulty);
    if (top.empty()) {
        std::cout << language.getText(TextKey::HallOfFameEmptyMessage) << "\n";
        return;
    }

    std::cout << std::left
              << std::setw(8) << language.getText(TextKey::HallOfFameHeaderRank)
              << std::setw(40) << language.getText(TextKey::HallOfFameHeaderName)
              << std::setw(10) << language.getText(TextKey::HallOfFameHeaderAttempts)
              << std::setw(10) << language.getText(TextKey::HallOfFameHeaderTime)
              << "\n";

    int rank = 1;
    for (const auto& entry : top) {
        std::string nameDisplay = entry.getPlayerName();
        if (entry.isNewGamePlus()) {
            nameDisplay += " " + language.getText(TextKey::HallOfFameNewGamePlusTag);
        }
        std::cout << std::left
                  << std::setw(8) << rank
                  << std::setw(40) << nameDisplay
                  << std::setw(10) << entry.getAttempts()
                  << std::setw(10) << entry.getTimeSeconds()
                  << "\n";
        ++rank;
    }
}

void HallOfFameScreen::run() {
    bool back = false;
    while (!back) {
        printTable();

        std::cout << "\n1. " << language.getText(TextKey::HallOfFameSwitchOption) << "\n";
        std::cout << "2. " << language.getText(TextKey::BackOption) << "\n";

        int choice = InputHelper::readIntInRange(
            language.getText(TextKey::ChoicePrompt), 1, 2, language.getText(TextKey::InvalidInput));

        if (choice == 1) {
            currentDifficulty = DifficultyLevel::next(currentDifficulty);
        } else {
            back = true;
        }
    }
}
