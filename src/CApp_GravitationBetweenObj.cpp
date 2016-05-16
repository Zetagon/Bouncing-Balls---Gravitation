#include "CApp.h"

int CApp::GravitationBetweenObj(Ball& ballOne,  Ball& ballTwo){
    double forceX;
    double forceY;
    double force;
    double distance = CalculateDistance(ballOne.x , ballOne.y, ballTwo.x, ballTwo.y);
    double deltaX = ballTwo.x - ballOne.x; //abs()
    double deltaY = ballTwo.y - ballOne.y; //abs()
    force = GRAVITATION_CONSTANT * ballOne.mass * ballTwo.mass / pow(distance , 2);


    double angle = atan(deltaY/deltaX);
    forceX = force * cos(angle);
    forceY = force *  sin(angle);
    if(deltaX < 0){
        ballOne.ApplyForce(-forceX,-forceY);
    }
    else{
        ballOne.ApplyForce(forceX, forceY);
    }
    return 0;
}

