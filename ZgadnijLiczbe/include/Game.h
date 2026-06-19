#pragma once

#include <string>
#include "DifficultyLevel.h"
#include "ILanguage.h"
#include "TextKey.h"
#include "Timer.h"

// ogolny przebieg jednej rozgrywki niezaleznie od trybu.
// algorytm (pytaj o liczbe, porownuj, podawaj podpowiedz).

class Game {
public:
    static constexpr int NO_LIMIT = 0;

    Game(DifficultyLevel difficultyLevel, const ILanguage& language, int maxAttempts);
    virtual ~Game() = default;

    // kazdy konkretny tryb gry musi podac swoja nazwe.
    virtual std::string getModeName() const = 0;

    // Domyslnie false. NewGamePlusGame nadpisuje na true.
    virtual bool isNewGamePlusMode() const;

    // Glowna petla rozgrywki.
    
    void play();

    Difficulty getDifficultyType() const;
    bool isBetMode() const;
    bool wasWon() const;
    int getAttemptsUsed() const;
    long long getElapsedSeconds() const;
    int getSecretNumber() const;

protected:
    DifficultyLevel difficultyLevel;
    const ILanguage& language;
    int secretNumber;
    int attemptsUsed;
    int maxAttempts;
    bool won;
    Timer timer;

    void rerollSecretNumber();

    virtual void onAttemptCompleted(int attemptsSoFar);
};
