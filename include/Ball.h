#ifndef BALL_H
#define BALL_H
#include "CApp.h"
#include "CTexture.h"
#include "Point.h"
#include <iostream>

class Ball
{
    public:
        Ball(SDL_Renderer* sdlRenderer,  char* File);

        SDL_Texture* Tex_Ball;

        double velocityX;
        double velocityY;
        double bounceCoefficient;
        double x;
        double y;
        int Width;
        int Height;
        int mass;
        double forceX;
        double forceY;
        bool canMove;
        static constexpr double lightspeed = 10;



        void RenderBall(SDL_Renderer* sdlRenderer, SDL_Texture* pointDest, SDL_Texture* ballDest);
        void ApplyForce(double forceX,double forceY);
        void ApplyAcceleration();
        void ApplyGravity();
        void ApplyFriction();
        void UpdateCoordinates();
        void OnBounce();
        bool DetectCollision(const Ball& otherBall);
    private:

        double Gravitational_Acceleration;




};

#endif // BALL_H
