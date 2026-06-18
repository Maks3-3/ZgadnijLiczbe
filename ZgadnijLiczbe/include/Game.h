#pragma once

#include <string>
#include "DifficultyLevel.h"
#include "ILanguage.h"
#include "TextKey.h"
#include "Timer.h"

// Game to klasa ABSTRAKCYJNA (ma czysto wirtualna metode getModeName) -
// reprezentuje ogolny "przebieg jednej rozgrywki" niezaleznie od trybu.
// Metoda play() implementuje wzorzec "szablonowej metody": caly glowny
// algorytm (pytaj o liczbe, porownuj, podawaj podpowiedz) jest wspolny,
// a haczyk onAttemptCompleted() pozwala potomkom (StandardGame,
// NewGamePlusGame) dorzucic wlasne zachowanie - to jest POLIMORFIZM.
class Game {
public:
    static constexpr int NO_LIMIT = 0;

    Game(DifficultyLevel difficultyLevel, const ILanguage& language, int maxAttempts);
    virtual ~Game() = default;

    // Czysto wirtualna - kazdy konkretny tryb gry musi podac swoja nazwe.
    virtual std::string getModeName() const = 0;

    // Domyslnie false; NewGamePlusGame nadpisuje na true.
    virtual bool isNewGamePlusMode() const;

    // Glowna petla rozgrywki (wzorzec szablonowej metody).
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

    // Haczyk wywolywany po kazdej nieudanej probie. Domyslnie nic nie robi.
    // NewGamePlusGame nadpisuje go, aby co kilka strzalow przelosowac liczbe.
    virtual void onAttemptCompleted(int attemptsSoFar);
};
