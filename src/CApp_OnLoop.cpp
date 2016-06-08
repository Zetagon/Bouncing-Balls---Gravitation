#include "CApp.h"
#include "QuadTree.h"
/**
*
*Handles data updates
*
*EX. Move character, move npc etc
*
*/
void CApp::OnLoop(){

    for(int i = 0   ; i < BallAry.size(); i++){

        if (BallAry.size() > 1){
                for(int j = i + 1; j < BallAry.size(); j++){
                    GravitationBetweenObj(BallAry[i], BallAry[j]);

                }


        }
//        BallAry[i].OnBounce();
        //BallAry[i].ApplyGravity();

        BallAry[i].ApplyAcceleration();
        BallAry[i].UpdateCoordinates();




    }
    //std::cout << "running";
    ballTree->clear();
    for(int i = 0; i < BallAry.size(); i ++ ){
        SDL_Rect tempRect = {BallAry.at(i).x,BallAry.at(i).y,BallAry.at(i).Width,BallAry.at(i).Height};
        ballTree->insertObj(tempRect, i);

    }

    for(int i = 0; i < BallAry.size(); i++){
        Ball ballOne = BallAry.at(i);
        SDL_Rect tempRect = {BallAry.at(i).x,BallAry.at(i).y,BallAry.at(i).Width,BallAry.at(i).Height};
        std::vector<int> returnIterator = ballTree->retrieveIterator(tempRect);
        for(int x = 0; x < returnIterator.size(); x++){

            Ball ballTwo = BallAry.at(returnIterator.at(x));
            double collisionDistance = ballOne.Width + ballTwo.Width;
            double distance = sqrt(pow(ballOne.x - ballTwo.x, 2) + pow(ballOne.y - ballTwo.y, 2));
            if(distance < collisionDistance){
                //std::cout << "Bounce";
            }
        }
        //collision detection here
        //Use the returnIterator for determining which balls are likely to collide
        //the ints tells you which position in BallAry are likely to collide with BallAry.at(i)
    }
//    std::cout << "FPS" << fpsTimer.CalculateFPS() << "\n";
//    std::cout << BallAry.size() << "\n";
}
