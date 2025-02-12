#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h> 
#include <atomic>

class Timer {

private:
    int secondsLeft;
    bool isPaused;

public:
    Timer(int minutes);
    void start();
    void pause();
    void resume();
    void reset();
    int getTimeLeft();

};
