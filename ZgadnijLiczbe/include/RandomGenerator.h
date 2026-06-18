#pragma once

// Hermetyzuje generator liczb pseudolosowych (std::mt19937), tak aby
// reszta programu nigdy nie musiala dotykac <random> bezposrednio.
class RandomGenerator {
public:
    RandomGenerator() = delete;

    // Zwraca losowa liczbe calkowita z przedzialu [min, max] (wlacznie).
    static int nextInt(int min, int max);
};
