#pragma once
#include "Timer.h"

using namespace std;

class WrestlingTimer {
private:
    Timer matchTimer;       // Main match timer
    Timer ridingTime;       // Riding time tracker
    int scoreRed;           // Red wrestler's score
    int scoreGreen;         // Green wrestler's score
    atomic<bool> isRidingTimeRunning;  // Is riding time active?
    atomic<bool> matchPaused;  // Is match paused?

public:
    WrestlingTimer(int matchMinutes);

    void startMatch();
    void pauseMatch();
    void resumeMatch();
    void resetMatch();

    void takedown(int wrestler);  // 2 points
    void reversal(int wrestler);  // 2 points
    void escape(int wrestler);    // 1 point
    void nearFall(int wrestler, int points); // 2 or 3 points

    void startRidingTime();
    void stopRidingTime();

    void displayScore();
};
