#pragma once

#include <chrono>

// Enkapsuluje pomiar czasu rozgrywki. Reszta programu nie musi wiedziec,
// ze pod spodem uzywany jest std::chrono::steady_clock.
class Timer {
private:
    std::chrono::steady_clock::time_point startTimePoint;
    std::chrono::steady_clock::time_point endTimePoint;
    bool running;

public:
    Timer();

    void start();
    void stop();
    long long elapsedSeconds() const;
};
