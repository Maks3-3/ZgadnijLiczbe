#pragma once

#include "ILanguage.h"

// PolishLanguage DZIEDZICZY po ILanguage i implementuje jego kontrakt
// po polsku. Razem z EnglishLanguage tworzy hierarchie dziedziczenia
// wykorzystywana polimorficznie w calej aplikacji.
class PolishLanguage : public ILanguage {
public:
    LanguageCode getCode() const override;
    std::string getText(TextKey key) const override;
    std::string getRandomTooLowMessage() const override;
    std::string getRandomTooHighMessage() const override;
};
