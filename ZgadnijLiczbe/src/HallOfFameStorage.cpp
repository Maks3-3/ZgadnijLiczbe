#include "HallOfFameStorage.h"
#include <fstream>
#include <sstream>
#include <vector>

std::string HallOfFameStorage::getFilePath() {
    return "hall_of_fame.dat";
}

HallOfFame HallOfFameStorage::load() {
    HallOfFame hof;
    std::ifstream file(getFilePath());
    if (!file.is_open()) {
        return hof;
    }

    std::string line;
    if (std::getline(file, line)) {
        try {
            hof.setTotalGamesPlayed(std::stoi(line));
        } catch (...) {
            hof.setTotalGamesPlayed(0);
        }
    }

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 5) {
            continue;
        }
        try {
            int diffIdx = std::stoi(tokens[0]);
            bool ngp = (tokens[1] == "1");
            int attempts = std::stoi(tokens[2]);
            long long timeSeconds = std::stoll(tokens[3]);
            std::string name = tokens[4];
            if (diffIdx < 0 || diffIdx > 2) {
                continue;
            }
            Difficulty diff = static_cast<Difficulty>(diffIdx);
            hof.addEntry(ScoreEntry(name, attempts, timeSeconds, diff, ngp));
        } catch (...) {
            continue;
        }
    }
    return hof;
}

void HallOfFameStorage::save(const HallOfFame& hallOfFame) {
    std::ofstream file(getFilePath());
    if (!file.is_open()) {
        return;
    }
    file << hallOfFame.getTotalGamesPlayed() << "\n";
    for (const auto& pair : hallOfFame.getAllEntries()) {
        for (const auto& entry : pair.second) {
            file << static_cast<int>(entry.getDifficulty()) << ";"
                 << (entry.isNewGamePlus() ? "1" : "0") << ";"
                 << entry.getAttempts() << ";"
                 << entry.getTimeSeconds() << ";"
                 << entry.getPlayerName() << "\n";
        }
    }
}
