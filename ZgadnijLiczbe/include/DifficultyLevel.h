#pragma once

#include "Difficulty.h"
#include "TextKey.h"

// Enkapsuluje informacje o konkretnym poziomie trudnosci: typ + zakres
// liczb (min/max). Liczby graniczne sa prywatne i dostepne tylko przez
// gettery - przyklad HERMETYZACJI.
class DifficultyLevel {
private:
    Difficulty type;
    int minValue;
    int maxValue;

public:
    explicit DifficultyLevel(Difficulty type);

    Difficulty getType() const;
    int getMin() const;
    int getMax() const;
    TextKey getNameKey() const;

    static Difficulty next(Difficulty current);
};
