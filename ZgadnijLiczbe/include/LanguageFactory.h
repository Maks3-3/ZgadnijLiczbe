#pragma once

#include <memory>
#include "ILanguage.h"
#include "LanguageCode.h"


class LanguageFactory {
public:
    LanguageFactory() = delete;

    static std::unique_ptr<ILanguage> create(LanguageCode code);
};
