#include "CApp.h"
#include <stdio.h>
/**
*Render all the images to the window
*
*
*
*
*/
void CApp::OnRender() {
    //Set background colour
    SDL_SetRenderDrawColor(Main_Renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(Main_Renderer,NULL);

    //These values can be anything
    SDL_Rect SrcR = {0,0, 270,1200};
    SDL_Rect DestR = {0,0, 270,1200};

//    if(CTexture::OnDraw(Main_Renderer, Tex_Test,DestR, SrcR) == false){
//        printf("On draw have failed!");
//    }



    SDL_RenderPresent(Main_Renderer);
}
