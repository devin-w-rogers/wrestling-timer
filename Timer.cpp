#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"

using namespace std;

Timer::Timer(int minutes) {
    secondsLeft = minutes * 60;
    isPaused = false;
}

void Timer::start() {
    while (secondsLeft > 0) {
        int minutes = secondsLeft / 60;
        int seconds = secondsLeft % 60;

        if (seconds == 0) {
            cout << " Time Left: " << minutes << ":00" << "\r";
        } else if (seconds < 10) {
            cout << " Time Left: " << minutes << ":0" << seconds << "\r";
        } else {
            cout << " Time Left: " << minutes << ":" << seconds << "\r";
        }


        this_thread::sleep_for(chrono::seconds(1)); 
        secondsLeft--;
    }
    cout << "Time is up!" << endl;
}

void Timer::pause() {

}

void Timer::resume() {

}

void Timer::reset() {

}

int Timer::getTimeLeft() {
    return secondsLeft;
}

