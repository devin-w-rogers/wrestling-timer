#include "Timer.h" 

using namespace std;

int main() 
{
    Timer myTimer(1);
    myTimer.start();

    return 0;
}


/*
g++ main.cpp Timer.cpp -o wrestling_timer
./wrestling_timer
*/