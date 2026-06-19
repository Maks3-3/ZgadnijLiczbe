#include "HallOfFame.h"
#include <algorithm>

HallOfFame::HallOfFame() : totalGamesPlayed(0) {
    entries[Difficulty::Easy] = {};
    entries[Difficulty::Medium] = {};
    entries[Difficulty::Hard] = {};
}

bool HallOfFame::addEntry(const ScoreEntry& entry) {
    auto& list = entries[entry.getDifficulty()];

    size_t betterCount = 0;
    for (const auto& existing : list) {
        if (ScoreEntry::better(existing, entry)) {
            ++betterCount;
        }
    }
    bool madeTop = betterCount < MAX_ENTRIES;

    list.push_back(entry);
    std::sort(list.begin(), list.end(), ScoreEntry::better);
    if (list.size() > MAX_ENTRIES) {
        list.erase(list.begin() + static_cast<long>(MAX_ENTRIES), list.end());
    }
    return madeTop;
}

const std::vector<ScoreEntry>& HallOfFame::getTop(Difficulty difficulty) const {
    return entries.at(difficulty);
}

void HallOfFame::clear() {
    for (auto& pair : entries) {
        pair.second.clear();
    }
}

int HallOfFame::getTotalGamesPlayed() const { return totalGamesPlayed; }
void HallOfFame::incrementGamesPlayed() { ++totalGamesPlayed; }
void HallOfFame::setTotalGamesPlayed(int value) { totalGamesPlayed = value; }

const std::map<Difficulty, std::vector<ScoreEntry>>& HallOfFame::getAllEntries() const {
    return entries;
}
