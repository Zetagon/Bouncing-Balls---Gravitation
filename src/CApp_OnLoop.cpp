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
                    GravitationBetweenObj(BallAry[j], BallAry[i]);

//                    std::cout << i << "  " << j << "\n";
//                    std::cout << j << "  " << i << "\n";
                }
////                GravitationBetweenObj(BallAry[BallAry.size() - 1],BallAry[0]);
//        GravitationBetweenObj(BallAry[0],BallAry[1]);
//        GravitationBetweenObj(BallAry[1],BallAry[0]);

        }
    //    BallAry[i].OnBounce();
        BallAry[i].UpdateCoordinates();


}
    std::cout << "FPS" << fpsTimer.CalculateFPS() << "\n";
//    std::cout << BallAry.size() << "\n";
}
