#include "CApp"

double CApp::GravitationBetweenObj(Ball ballOne, ballTwo){
    double forceX;
    double forceY;
    double force;

    force = GRAVITATION_CONSTANT * ballOne.mass * ballTwo.mass / pow(CalculateDistance(ballOne.x , ballOne.y, ballTwo. x, ballTwo.y);
    return 0.0;
}

