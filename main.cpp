#include "Timer.h" 
#include "WrestlingTimer.h" 

using namespace std;

int main() 
{
    //Timer myTimer(1);
    //myTimer.start();

    WrestlingTimer myTimer(1);
    myTimer.startMatch();

    return 0;
}


/*
g++ main.cpp Timer.cpp WrestlingTimer.cpp -o wrestling_timer 
./wrestling_timer
*/