#include "Ball.h"

Ball::Ball(SDL_Renderer* sdlRenderer )
{
    int tempX;
    int tempY;

    Width = 100;
    Height = 100;
    mass = 10;
    velocityX = 1;
    velocityY = -2;
    Gravitational_Acceleration = 0.005;
    bounceCoefficient = 0.9;
    SDL_GetMouseState( &tempX, &tempY );
    x = tempX;
    y = tempY;
    x -= Width/2;
    y -= Height/2;

    Tex_Ball = CTexture::OnLoadImage("Ball2.png", sdlRenderer);

}


void Ball::RenderBall(SDL_Renderer* sdlRenderer){
    SDL_Rect DestR = {round(x),round(y),Width, Height};
    CTexture::OnDraw(sdlRenderer,Tex_Ball,&DestR);
}

void Ball::ApplyForce(double forceX,double forceY){
    double accX = forceX/mass;
    double accY = forceY/mass;
    velocityX += accX;
    velocityY += accY;

}

void Ball::ApplyGravity(){
    ApplyForce(0,Gravitational_Acceleration * mass);
}

void Ball::UpdateCoordinates(){
    x += velocityX;
    y += velocityY;
}

void Ball::OnBounce(){
    if (y >= CApp::screen.h - 100){
        velocityY *= -bounceCoefficient;
        y = CApp::screen.h -100;
    }
    if (x >= CApp::screen.w){
        velocityX *= -bounceCoefficient;
        x = CApp::screen.w;
    }
    if (x <= 0){
        velocityX *= -bounceCoefficient;
        x = 0;
    }
}
