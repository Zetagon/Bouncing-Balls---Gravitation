#include "Ball.h"

Ball::Ball(SDL_Renderer* sdlRenderer, char* File)
{
//    double randvelocityX = rand(void) %200 / 100.0;
//    double randvelocityY = rand(void) %200 / 100.0;


    int tempX;
    int tempY;

    Width = 50;
    Height = 50;
    mass = 100;
    velocityX = 0; //(rand() %300 -150) / 100.0;
    velocityY =  0;//(rand() %300 - 300) / 100.0;
    forceX = 0;
    forceY = 0;
    Gravitational_Acceleration = 0.005;
    bounceCoefficient = 0.9;
//    SDL_GetMouseState( &tempX, &tempY );
    x =   10;
    y =   10;



    Tex_Ball = CTexture::OnLoadImage(File, sdlRenderer);

}


void Ball::RenderBall(SDL_Renderer* sdlRenderer){
    if(CApp::drawPath){
        Point tempPoint(x , y);
        pointAry.push_back(tempPoint);
    }
        for(int i = 0; i < pointAry.size(); i++){
            pointAry[i].renderPoint(sdlRenderer);
        }

    SDL_Rect DestR = {round(x - (Width/2.0)) + CApp::scrollModifierX ,round(y - (Height/ 2.0)) + CApp::scrollModifierY,Width, Height};
    CTexture::OnDraw(sdlRenderer,Tex_Ball,&DestR);

}

void Ball::ApplyForce(double fX,double fY){
    forceX += fX  ;
    forceY += fY  ;


}

void Ball::ApplyAcceleration(){
    double accX = forceX/mass;
    double accY = forceY/mass;
    velocityX += accX * pow(CApp::SlowMotionValue,2);
    velocityY += accY * pow(CApp::SlowMotionValue,2);
//    if(velocityX > lightspeed)velocityX = 0.99 * lightspeed;
//    if(velocityY > lightspeed)velocityY = 0.99 * lightspeed;
    forceX = 0;
    forceY = 0;

    std::cout << forceX;
    std::cout << velocityY << "\n";
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
