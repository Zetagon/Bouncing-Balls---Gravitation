#include "CApp.h"
#include <stdio.h>
/**
*Render all the images to the window
*
*
*
*
*/
SDL_Rect CApp::screen = {0,0,100,100};
void CApp::OnRender() {
    //Set background colour
    SDL_SetRenderDrawColor(Main_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Main_Renderer,NULL);

    //These values can be anything
    SDL_Rect SrcR = {0,0, 270,1200};


//    if(CTexture::OnDraw(Main_Renderer, Tex_Test,DestR, SrcR) == false){
//        printf("On draw have failed!");
//    }


//    Ball newBall(Main_Renderer);
//    SDL_Rect DestR = {newBall.x - 50,newBall.y - 50 , 100,100};
//    CTexture::OnDraw(Main_Renderer,newBall.Tex_Ball,&DestR);

    for(int i = 0   ; i < BallAry.size(); i++){
        BallAry.at(i).RenderBall(Main_Renderer);
    }

    SDL_RenderPresent(Main_Renderer);
}
