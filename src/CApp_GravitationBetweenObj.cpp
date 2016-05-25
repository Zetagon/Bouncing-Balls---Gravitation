#include "CApp.h"

int CApp::GravitationBetweenObj(Ball& ballOne,  Ball& ballTwo){
    //using newtons gravitational law
    double forceX = 0;
    double forceY = 0;
    double force;
    double distance = CalculateDistance(ballOne.x , ballOne.y, ballTwo.x, ballTwo.y);
    double deltaX = ballTwo.x - ballOne.x; //abs()
    double deltaY = ballTwo.y - ballOne.y; //abs()
    force = GRAVITATION_CONSTANT * ballOne.mass * ballTwo.mass / pow(distance , 2);


    double angle = atan(deltaY/deltaX);
    forceX = force * cos(angle);
    forceY = force *  sin(angle);
//    if(ballOne.DetectCollision(ballTwo)){
//        std::cout << distance;  bouncing doesn't work
//        forceX *= -10;
//        forceY *= -10;
//
//    }
    if(deltaX < 0){
        ballOne.ApplyForce(-forceX,-forceY);
        ballTwo.ApplyForce(forceX,forceY);
//        ballOne.ApplyForce(forceX, forceY);
//        ballTwo.ApplyForce(-forceX,-forceY);
    }
    else{
        ballOne.ApplyForce(forceX, forceY);
        ballTwo.ApplyForce(-forceX,-forceY);
//        ballOne.ApplyForce(-forceX,-forceY);
//        ballTwo.ApplyForce(forceX,forceY);
    }
    return 0;
}

