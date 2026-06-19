#include "ScoreEntry.h"

ScoreEntry::ScoreEntry(const std::string& playerName, int attempts, long long timeSeconds,
                        Difficulty difficulty, bool newGamePlus)
    : playerName(playerName), attempts(attempts), timeSeconds(timeSeconds),
      difficulty(difficulty), newGamePlus(newGamePlus) {}

const std::string& ScoreEntry::getPlayerName() const { return playerName; }
int ScoreEntry::getAttempts() const { return attempts; }
long long ScoreEntry::getTimeSeconds() const { return timeSeconds; }
Difficulty ScoreEntry::getDifficulty() const { return difficulty; }
bool ScoreEntry::isNewGamePlus() const { return newGamePlus; }

bool ScoreEntry::better(const ScoreEntry& a, const ScoreEntry& b) {
    if (a.attempts != b.attempts) {
        return a.attempts < b.attempts;
    }
    return a.timeSeconds < b.timeSeconds;
}
