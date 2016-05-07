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
        //BallAry[i].ApplyForce(0.005,0);

        if(BallAry[i].y >= screen.h -100 && round(BallAry[i].velocityY && BallAry[i].velocityX) == 0){
            BallAry.erase(BallAry.begin()+i);
        }
}

}
