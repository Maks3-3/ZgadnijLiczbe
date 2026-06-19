#include "Game.h"
#include "InputHelper.h"
#include "RandomGenerator.h"
#include <iostream>

Game::Game(DifficultyLevel difficultyLevel, const ILanguage& language, int maxAttempts)
    : difficultyLevel(difficultyLevel), language(language), secretNumber(0),
      attemptsUsed(0), maxAttempts(maxAttempts), won(false) {}

void Game::rerollSecretNumber() {
    secretNumber = RandomGenerator::nextInt(difficultyLevel.getMin(), difficultyLevel.getMax());
}

void Game::onAttemptCompleted(int attemptsSoFar) {
    (void)attemptsSoFar;

}

bool Game::isNewGamePlusMode() const { return false; }

Difficulty Game::getDifficultyType() const { return difficultyLevel.getType(); }
bool Game::isBetMode() const { return maxAttempts > 0; }
bool Game::wasWon() const { return won; }
int Game::getAttemptsUsed() const { return attemptsUsed; }
long long Game::getElapsedSeconds() const { return timer.elapsedSeconds(); }
int Game::getSecretNumber() const { return secretNumber; }

void Game::play() {
    attemptsUsed = 0;
    won = false;
    rerollSecretNumber();
    timer.start();

    while (true) {
        ++attemptsUsed;
        std::cout << "\n" << language.getText(TextKey::AttemptLabel) << attemptsUsed << "\n";

        int guess = InputHelper::readIntInRange(
            language.getText(TextKey::GuessPrompt),
            -1000000, 1000000,
            language.getText(TextKey::InvalidInput)
        );

        if (guess == secretNumber) {
            won = true;
            timer.stop();
            return;
        }

        if (guess < secretNumber) {
            std::cout << language.getRandomTooLowMessage() << "\n";
        } else {
            std::cout << language.getRandomTooHighMessage() << "\n";
        }

        onAttemptCompleted(attemptsUsed);

        if (maxAttempts > 0 && attemptsUsed >= maxAttempts) {
            won = false;
            timer.stop();
            return;
        }
    }
}
