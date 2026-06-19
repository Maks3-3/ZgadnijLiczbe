#pragma once

#include "ILanguage.h"


class PolishLanguage : public ILanguage {
public:
    LanguageCode getCode() const override;
    std::string getText(TextKey key) const override;
    std::string getRandomTooLowMessage() const override;
    std::string getRandomTooHighMessage() const override;
};
