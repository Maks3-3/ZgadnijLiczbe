#include "Settings.h"
#include "LanguageFactory.h"

Settings::Settings() : language(LanguageFactory::create(LanguageCode::PL)), askBetMode(true) {}

Settings::Settings(LanguageCode code, bool askBetMode)
    : language(LanguageFactory::create(code)), askBetMode(askBetMode) {}

const ILanguage& Settings::getLanguage() const { return *language; }
LanguageCode Settings::getLanguageCode() const { return language->getCode(); }

void Settings::setLanguage(LanguageCode code) {
    language = LanguageFactory::create(code);
}

bool Settings::isAskBetMode() const { return askBetMode; }
void Settings::setAskBetMode(bool value) { askBetMode = value; }
