#pragma once

#include <string>
#include "TextKey.h"
#include "LanguageCode.h"

// ILanguage to klasa abstrakcyjna (czysty interfejs) - przyklad ABSTRAKCJI.
// Definiuje KONTRAKT: "cos, co umie podac przetlumaczony tekst",
// bez ujawniania, jak konkretnie ten tekst jest przechowywany/budowany.
// Nie da sie utworzyc obiektu typu ILanguage - tylko jej konkretnych potomkow.
class ILanguage {
public:
    virtual ~ILanguage() = default;

    virtual LanguageCode getCode() const = 0;
    virtual std::string getText(TextKey key) const = 0;
    virtual std::string getRandomTooLowMessage() const = 0;
    virtual std::string getRandomTooHighMessage() const = 0;
};
