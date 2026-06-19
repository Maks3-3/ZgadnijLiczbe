#include "LanguageFactory.h"
#include "PolishLanguage.h"
#include "EnglishLanguage.h"

std::unique_ptr<ILanguage> LanguageFactory::create(LanguageCode code) {
    switch (code) {
        case LanguageCode::EN:
            return std::make_unique<EnglishLanguage>();
        case LanguageCode::PL:
        default:
            return std::make_unique<PolishLanguage>();
    }
}
