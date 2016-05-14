#include "Timer.h"



Timer::Timer()
{
    //ctor
    currentTime = 0;
    lastTime = 0;
}

Timer::~Timer()
{
    //dtor
}
/**
*
*Returns the time past since the last call. If it is the first call, return the time since the program started.
*The time is given in milliseconds.
*
*
*
*/
uint32_t Timer::TimeSince(){
    currentTime = SDL_GetTicks();
    if(lastTime == 0){
        lastTime = currentTime;
        return SDL_GetTicks();
    }
    else{
        uint32_t temp = currentTime - lastTime;
        lastTime = currentTime;
        return temp;
    }
}

int Timer::CalculateFPS(){
    double tempTime = TimeSince()/1000.0;
    return round(1/tempTime);

}
