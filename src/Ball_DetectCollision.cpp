#include "Ball.h"

bool Ball::DetectCollision(const Ball& otherBall){
    double deltaX = x - otherBall.x;
    double deltaY = y - otherBall.y;

    double distance = sqrt(pow(deltaX,2) + pow(deltaY,2));
    if(distance < Width / 2.0 + otherBall.Width /  2.0){
        return true;
    }
    else{
        return false;
    }
}
