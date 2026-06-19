#pragma once

#include <chrono>


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
