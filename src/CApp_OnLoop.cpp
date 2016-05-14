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
        BallAry[i].ApplyGravity();
        BallAry[i].OnBounce();
        BallAry[i].UpdateCoordinates();
        BallAry[i].ApplyFriction();


        if(BallAry[i].y >= screen.h -100 && BallAry[i].velocityY== 0 && BallAry[i].velocityX == 0){
            BallAry.erase(BallAry.begin()+i);
        }
}
    std::cout << fpsTimer.CalculateFPS() << "\n";
//    std::cout << BallAry.size() << "\n";
}
