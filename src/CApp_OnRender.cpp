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



//    if(CTexture::OnDraw(Main_Renderer, Tex_Test,DestR, SrcR) == false){
//        printf("On draw have failed!");
//    }


//    Ball newBall(Main_Renderer);
//    SDL_Rect DestR = {newBall.x - 50,newBall.y - 50 , 100,100};
//    CTexture::OnDraw(Main_Renderer,newBall.Tex_Ball,&DestR);

    double zoomModifierX = zoomModifier * screen.w;
    double zoomModifierY = zoomModifier * screen.h;

    //render to the main texture, it will later be rendered to the default target.
    SDL_SetRenderTarget(Main_Renderer, ballTex);
    SDL_RenderClear(Main_Renderer);
    SDL_Rect destR = {scrollModifierX,scrollModifierY,screen.w* MAX_ZOOM, screen.h* MAX_ZOOM};
    if(SDL_RenderCopy(Main_Renderer,pointTex,NULL,&destR) < 0){
         printf("Rendercopy in OnRender is not working! The error is: %s \n",SDL_GetError());
    }



    for(int i = 0   ; i < BallAry.size(); i++){
        BallAry.at(i).RenderBall(Main_Renderer, pointTex, ballTex);
    }
    //render to main target i.e. the "screen"
    SDL_SetRenderTarget(Main_Renderer, NULL);
    SDL_Rect temprect = {0,0,screen.w+zoomModifierX ,screen.h+zoomModifierY};
    if(SDL_RenderCopy(Main_Renderer,ballTex,NULL,&temprect) < 0){
         printf("Rendercopy in OnRender is not working! The error is: %s \n",SDL_GetError());
    }



    SDL_RenderPresent(Main_Renderer);
}
