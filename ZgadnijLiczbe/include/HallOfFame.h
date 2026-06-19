#pragma once

#include <map>
#include <vector>
#include "Difficulty.h"
#include "ScoreEntry.h"

// Zarzadza rankingami TOP5 dla kazdego poziomu trudnosci.
class HallOfFame {
private:
    static constexpr size_t MAX_ENTRIES = 5;

    std::map<Difficulty, std::vector<ScoreEntry>> entries;
    int totalGamesPlayed;

public:
    HallOfFame();

    
    bool addEntry(const ScoreEntry& entry);

    const std::vector<ScoreEntry>& getTop(Difficulty difficulty) const;

    void clear();

    int getTotalGamesPlayed() const;
    void incrementGamesPlayed();
    void setTotalGamesPlayed(int value);

    
    const std::map<Difficulty, std::vector<ScoreEntry>>& getAllEntries() const;
};
