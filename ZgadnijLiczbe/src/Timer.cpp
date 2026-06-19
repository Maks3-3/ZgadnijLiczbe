#include "Timer.h"

Timer::Timer() : running(false) {}

void Timer::start() {
    startTimePoint = std::chrono::steady_clock::now();
    running = true;
}

void Timer::stop() {
    endTimePoint = std::chrono::steady_clock::now();
    running = false;
}

long long Timer::elapsedSeconds() const {
    auto end = running ? std::chrono::steady_clock::now() : endTimePoint;
    return std::chrono::duration_cast<std::chrono::seconds>(end - startTimePoint).count();
}
