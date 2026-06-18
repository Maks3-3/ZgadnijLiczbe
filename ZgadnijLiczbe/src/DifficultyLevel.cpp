#include "DifficultyLevel.h"

DifficultyLevel::DifficultyLevel(Difficulty type) : type(type), minValue(1), maxValue(50) {
    switch (type) {
        case Difficulty::Easy:
            minValue = 1;
            maxValue = 50;
            break;
        case Difficulty::Medium:
            minValue = 1;
            maxValue = 100;
            break;
        case Difficulty::Hard:
            minValue = 1;
            maxValue = 250;
            break;
    }
}

Difficulty DifficultyLevel::getType() const { return type; }
int DifficultyLevel::getMin() const { return minValue; }
int DifficultyLevel::getMax() const { return maxValue; }

TextKey DifficultyLevel::getNameKey() const {
    switch (type) {
        case Difficulty::Easy: return TextKey::DifficultyEasyLabel;
        case Difficulty::Medium: return TextKey::DifficultyMediumLabel;
        case Difficulty::Hard: return TextKey::DifficultyHardLabel;
    }
    return TextKey::DifficultyEasyLabel;
}

Difficulty DifficultyLevel::next(Difficulty current) {
    switch (current) {
        case Difficulty::Easy: return Difficulty::Medium;
        case Difficulty::Medium: return Difficulty::Hard;
        case Difficulty::Hard: return Difficulty::Easy;
    }
    return Difficulty::Easy;
}
