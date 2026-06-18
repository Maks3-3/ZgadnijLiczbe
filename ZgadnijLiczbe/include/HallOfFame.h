#pragma once

#include <map>
#include <vector>
#include "Difficulty.h"
#include "ScoreEntry.h"

// Zarzadza rankingami TOP5 dla kazdego poziomu trudnosci. Wewnetrzna
// struktura danych (mapa) jest prywatna - na zewnatrz wystawiane sa
// tylko bezpieczne operacje (addEntry/getTop/clear). To jest HERMETYZACJA:
// caly mechanizm sortowania i przycinania do 5 najlepszych jest schowany.
class HallOfFame {
private:
    static constexpr size_t MAX_ENTRIES = 5;

    std::map<Difficulty, std::vector<ScoreEntry>> entries;
    int totalGamesPlayed;

public:
    HallOfFame();

    // Dodaje wpis do rankingu danego poziomu trudnosci, sortuje i przycina
    // do MAX_ENTRIES. Zwraca true, jesli wpis trafil do TOP5.
    bool addEntry(const ScoreEntry& entry);

    const std::vector<ScoreEntry>& getTop(Difficulty difficulty) const;

    // Czysci wszystkie rekordy (wymaga potwierdzenia na poziomie ekranu ustawien).
    void clear();

    int getTotalGamesPlayed() const;
    void incrementGamesPlayed();
    void setTotalGamesPlayed(int value);

    // Udostepnia surowe dane do zapisu na dysk (HallOfFameStorage).
    const std::map<Difficulty, std::vector<ScoreEntry>>& getAllEntries() const;
};
