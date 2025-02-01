#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h> // _kbhit() and _getch()
#include "Timer.h"

using namespace std;

Timer::Timer(int minutes) {
    secondsLeft = minutes * 60;
    isPaused = false;
}

void Timer::start() {
    std::thread inputThread([this]() { // separate thread to listen for input
    while (secondsLeft > 0) {
        if (_kbhit()) {  // check if a key was pressed
            char ch = _getch();  // get the key press without waiting for Enter
            if ((ch == 'p' || ch == 'P') && isPaused == false) {
                pause();
            } else if ((ch == 'r' || ch == 'R') && isPaused == true) {
                resume();
            }
        }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    });

    while (secondsLeft > 0) {
        if (isPaused) {
            this_thread::sleep_for(chrono::milliseconds(500)); 
            continue;
        }


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

    inputThread.join();
}

void Timer::pause() {
    isPaused = true;
    cout << "\nTimer paused. Press 'R' to resume.\n";
}

void Timer::resume() {
    isPaused = false;
    std::cout << "Timer resumed.\n";
}

void Timer::reset() {

}

int Timer::getTimeLeft() {
    return secondsLeft;
}

