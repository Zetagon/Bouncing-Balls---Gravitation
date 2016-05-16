#ifndef BALL_H
#define BALL_H
#include "CApp.h"
#include "CTexture.h"
#include <iostream>

class Ball
{
    public:
        Ball(SDL_Renderer* sdlRenderer,  char* File, double vx, double vy, int m);

        SDL_Texture* Tex_Ball;

        double velocityX;
        double velocityY;
        double bounceCoefficient;
        double x;
        double y;
        int mass;

        void RenderBall(SDL_Renderer* sdlRenderer);
        void ApplyForce(double forceX,double forceY);
        void ApplyGravity();
        void ApplyFriction();
        void UpdateCoordinates();
        void OnBounce();
    private:

        double Gravitational_Acceleration;

        int Width;
        int Height;

};

#endif // BALL_H
