#pragma once

#include "ILanguage.h"
#include "MenuChoice.h"



class WelcomeScreen {
private:
    const ILanguage& language;
    bool hallOfFameAvailable;

public:
    WelcomeScreen(const ILanguage& language, bool hallOfFameAvailable);

    MenuChoice run() const;
};
