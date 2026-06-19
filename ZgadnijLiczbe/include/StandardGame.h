#pragma once

#include "Game.h"

// Standardowy tryb "Zgadnij liczbe 1".
// liczba nigdy nie jest przelosowywana.
// Moze dzialac w trybie zakladu (maxAttempts > 0).
class StandardGame : public Game {
public:
    StandardGame(DifficultyLevel difficultyLevel, const ILanguage& language, int maxAttempts);

    std::string getModeName() const override;
};
