#ifndef BALL_H
#define BALL_H
#include "CApp.h"
#include "CTexture.h"
#include <iostream>

class Ball
{
    public:
        Ball(SDL_Renderer* sdlRenderer);

        SDL_Texture* Tex_Ball;

        double velocityX;
        double velocityY;
        double bounceCoefficient;
        double x;
        double y;

        void RenderBall(SDL_Renderer* sdlRenderer);
        void ApplyForce(double forceX,double forceY);
        void ApplyGravity();
        void UpdateCoordinates();
        void OnBounce();
    private:

        double Gravitational_Acceleration;
        int mass;
        int Width;
        int Height;

};

#endif // BALL_H
