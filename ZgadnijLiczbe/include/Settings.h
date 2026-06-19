#pragma once

#include <memory>
#include "ILanguage.h"
#include "LanguageCode.h"

// Przechowuje aktualny jezyk oraz flage "czy pytac o tryb zakladu".

class Settings {
private:
    std::unique_ptr<ILanguage> language;
    bool askBetMode;

public:
    // Domyslnie: jezyk pl, pytanie o tryb zakladu wlaczone.
    Settings();
    Settings(LanguageCode code, bool askBetMode);

    const ILanguage& getLanguage() const;
    LanguageCode getLanguageCode() const;
    void setLanguage(LanguageCode code);

    bool isAskBetMode() const;
    void setAskBetMode(bool value);
};
