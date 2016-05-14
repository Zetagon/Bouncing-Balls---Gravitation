#include "Ball.h"

Ball::Ball(SDL_Renderer* sdlRenderer )
{
//    double randvelocityX = rand(void) %200 / 100.0;
//    double randvelocityY = rand(void) %200 / 100.0;


    int tempX;
    int tempY;

    Width = 100;
    Height = 100;
    mass = 10;
    velocityX = 2; //(rand() %300 -150) / 100.0;
    velocityY =  -1;//(rand() %300 - 300) / 100.0;
    Gravitational_Acceleration = 0.005;
    bounceCoefficient = 1;
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
    velocityX += accX * CApp::SlowMotionValue;
    velocityY += accY * CApp::SlowMotionValue;

}

void Ball::ApplyGravity(){
    ApplyForce(0,Gravitational_Acceleration * mass);
}

void Ball::UpdateCoordinates(){
    x += velocityX * CApp::SlowMotionValue;
    y += velocityY * CApp::SlowMotionValue;
}

void Ball::ApplyFriction(){
//    if (y == CApp::screen.h - 100){
//        if(velocityX < 0){
//            ApplyForce(10,0);
//        }
//        if(velocityY > 0){
//            ApplyForce(-10,0);
//        }
//    }
    if (y >= CApp::screen.h - 101){
        velocityX *= 0.99;
    }
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
    if (y <= 0){
        velocityY *= -bounceCoefficient;
        y = 0;
    }
}
