#pragma once

#include <string>
#include "TextKey.h"
#include "LanguageCode.h"

class ILanguage {
public:
    virtual ~ILanguage() = default;

    virtual LanguageCode getCode() const = 0;
    virtual std::string getText(TextKey key) const = 0;
    virtual std::string getRandomTooLowMessage() const = 0;
    virtual std::string getRandomTooHighMessage() const = 0;
};
