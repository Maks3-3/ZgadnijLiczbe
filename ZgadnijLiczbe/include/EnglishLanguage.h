#pragma once

#include "ILanguage.h"

// EnglishLanguage DZIEDZICZY po ILanguage i implementuje jego kontrakt
// po angielsku. Wybor pomiedzy PolishLanguage i EnglishLanguage w czasie
// dzialania programu (przez Settings) to przyklad POLIMORFIZMU.
class EnglishLanguage : public ILanguage {
public:
    LanguageCode getCode() const override;
    std::string getText(TextKey key) const override;
    std::string getRandomTooLowMessage() const override;
    std::string getRandomTooHighMessage() const override;
};
