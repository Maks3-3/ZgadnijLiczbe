#pragma once


class RandomGenerator {
public:
    RandomGenerator() = delete;

    // Zwraca losowa liczbe calkowita z przedzialu [min, max]
    static int nextInt(int min, int max);
};
