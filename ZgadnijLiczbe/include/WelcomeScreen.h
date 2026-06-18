#pragma once

#include "ILanguage.h"
#include "MenuChoice.h"

// Reprezentuje ekran powitalny jako obiekt: konstruktor przyjmuje
// wszystko, czego ekran potrzebuje do wyswietlenia siebie, a run()
// zwraca decyzje uzytkownika. Opcja "Hall of Fame" jest pokazywana
// tylko, jesli rozegrano juz przynajmniej jedna gre.
class WelcomeScreen {
private:
    const ILanguage& language;
    bool hallOfFameAvailable;

public:
    WelcomeScreen(const ILanguage& language, bool hallOfFameAvailable);

    MenuChoice run() const;
};
