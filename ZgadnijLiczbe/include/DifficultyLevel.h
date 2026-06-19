#pragma once

#include "Difficulty.h"
#include "TextKey.h"

// liczb (min/max). Liczby graniczne sa prywatne
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
