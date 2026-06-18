#pragma once

#include <memory>
#include "ILanguage.h"
#include "LanguageCode.h"

// Klasa statyczna (narzedziowa) odpowiedzialna wylacznie za tworzenie
// odpowiedniego obiektu jezyka na podstawie kodu. Reszta programu nie
// musi znac konkretnych klas PolishLanguage/EnglishLanguage - tylko ILanguage.
class LanguageFactory {
public:
    LanguageFactory() = delete;

    static std::unique_ptr<ILanguage> create(LanguageCode code);
};
