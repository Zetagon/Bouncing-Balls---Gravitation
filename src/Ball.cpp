#include "Ball.h"

Ball::Ball(SDL_Renderer* sdlRenderer, char* File, double vx, double vy, int m)
{
//    double randvelocityX = rand(void) %200 / 100.0;
//    double randvelocityY = rand(void) %200 / 100.0;


    int tempX;
    int tempY;

    Width = 50;
    Height = 50;
    mass = m;
    velocityX = vx; //(rand() %300 -150) / 100.0;
    velocityY =  vy;//(rand() %300 - 300) / 100.0;
    Gravitational_Acceleration = 0.005;
    bounceCoefficient = 0.99;
    SDL_GetMouseState( &tempX, &tempY );
    x =   tempX;
    y =   tempY;
    x -= Width/2;
    y -= Height/2;

    Tex_Ball = CTexture::OnLoadImage(File, sdlRenderer);

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
