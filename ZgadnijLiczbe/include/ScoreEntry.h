#pragma once

#include <string>
#include "Difficulty.h"

// Reprezentuje pojedynczy wpis w Hall of Fame.

class ScoreEntry {
private:
    std::string playerName;
    int attempts;
    long long timeSeconds;
    Difficulty difficulty;
    bool newGamePlus;

public:
    ScoreEntry(const std::string& playerName, int attempts, long long timeSeconds,
               Difficulty difficulty, bool newGamePlus);

    const std::string& getPlayerName() const;
    int getAttempts() const;
    long long getTimeSeconds() const;
    Difficulty getDifficulty() const;
    bool isNewGamePlus() const;

    // Zwraca true, jesli wpis "a" powinien byc wyzej w rankingu niz "b":
    // mniej prob wygrywa, a przy remisie - krotszy czas.
    static bool better(const ScoreEntry& a, const ScoreEntry& b);
};
