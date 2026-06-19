#include "SettingsStorage.h"
#include <fstream>

std::string SettingsStorage::getFilePath() {
    return "settings.dat";
}

Settings SettingsStorage::load() {
    std::ifstream file(getFilePath());
    if (!file.is_open()) {
        return Settings();
    }

    std::string langLine;
    std::string betLine;
    LanguageCode code = LanguageCode::PL;
    bool askBet = true;

    if (std::getline(file, langLine)) {
        code = (langLine == "EN") ? LanguageCode::EN : LanguageCode::PL;
    }
    if (std::getline(file, betLine)) {
        askBet = (betLine == "1");
    }

    return Settings(code, askBet);
}

void SettingsStorage::save(const Settings& settings) {
    std::ofstream file(getFilePath());
    if (!file.is_open()) {
        return;
    }
    file << (settings.getLanguageCode() == LanguageCode::EN ? "EN" : "PL") << "\n";
    file << (settings.isAskBetMode() ? "1" : "0") << "\n";
}
