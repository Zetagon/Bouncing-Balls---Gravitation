#include "CApp.h"
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
//    std::cout << "FPS" << fpsTimer.CalculateFPS() << "\n";
//    std::cout << BallAry.size() << "\n";
}
