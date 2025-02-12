#include "WrestlingTimer.h"

using namespace std;

WrestlingTimer::WrestlingTimer(int matchMinutes) 
    : matchTimer(matchMinutes), ridingTime(0), scoreRed(0), scoreGreen(0), isRidingTimeRunning(false), matchPaused(false) {}

// Starts the match timer and listens for input
void WrestlingTimer::startMatch() {
    thread inputThread([this]() { 
        while (true) {
            if (_kbhit()) {
                char ch = _getch();
                if (ch == 'p' || ch == 'P') pauseMatch();
                else if (ch == 'r' || ch == 'R') resumeMatch();
                else if (ch == 'a' || ch == 'A') takedown(1);  // Red takedown
                else if (ch == 'z' || ch == 'Z') takedown(2);  // Green takedown
                else if (ch == 'e' || ch == 'E') escape(1);    // Red escape
                else if (ch == 'w' || ch == 'W') escape(2);    // Green escape
                else if (ch == 'v' || ch == 'V') reversal(1);  // Red reversal
                else if (ch == 'b' || ch == 'B') reversal(2);  // Green reversal
                cout << " SCORE ---- Red: " << scoreRed << "   Green: " << scoreGreen << endl; //"\r"
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });

    matchTimer.start();
    inputThread.join();
}

// Pauses the match
void WrestlingTimer::pauseMatch() {
    matchTimer.pause();
}

// Resumes the match
void WrestlingTimer::resumeMatch() {
    matchTimer.resume();
}

// Resets the match
void WrestlingTimer::resetMatch() {

}

// Scorekeeping Functions
void WrestlingTimer::takedown(int wrestler) {
    if (wrestler == 1) {
        scoreRed = scoreRed + 3;
    } else if (wrestler == 2) {
        scoreGreen = scoreGreen + 3;
    }
}

void WrestlingTimer::reversal(int wrestler) {
    if (wrestler == 1) {
        scoreRed = scoreRed + 2;
    } else if (wrestler == 2) {
        scoreGreen = scoreGreen + 2;
    }
}

void WrestlingTimer::escape(int wrestler) {
    if (wrestler == 1) {
        scoreRed = scoreRed + 1;
    } else if (wrestler == 2) {
        scoreGreen = scoreGreen + 1;
    }
}

void WrestlingTimer::nearFall(int wrestler, int points) {
    if (wrestler == 1) {
        scoreRed = scoreRed + points;
    } else if (wrestler == 2) {
        scoreGreen = scoreGreen + points;
    }
}

// Riding Time Functions
void WrestlingTimer::startRidingTime() {

}

void WrestlingTimer::stopRidingTime() {

}

// Display Score
void WrestlingTimer::displayScore() {

}