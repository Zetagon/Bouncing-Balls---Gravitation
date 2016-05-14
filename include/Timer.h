#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
#include <cmath>
#include <SDL.h>


class Timer
{
    public:
        Timer();
        virtual ~Timer();

        uint32_t TimeSince();
        int CalculateFPS();
    protected:

    private:
        uint32_t currentTime; //Only used in TimeSince()
        uint32_t lastTime; //Only used in TimeSince()
};

#endif // TIMER_H
