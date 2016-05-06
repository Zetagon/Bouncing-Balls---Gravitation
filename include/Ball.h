#ifndef BALL_H
#define BALL_H
#include "CApp.h"
#include "CTexture.h"
#include <iostream>

class Ball
{
    public:
        Ball();



    private:
        double velocityX;
        double velocityY;
        SDL_Point coordinate;
        SDL_Texture* Tex_Ball;
};

#endif // BALL_H
