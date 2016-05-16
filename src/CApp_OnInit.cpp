#include "CApp.h"

/**
*
*Initialize SDL, SDL_window, SDL_renderer,images etc.
*
*
*@return false if it fails, true if successful
*
*/
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
    srand(time(NULL));


    if(SDL_GetDisplayBounds(0,&screen) != 0){
        std::cout << "error!";
    }
    if((window = SDL_CreateWindow("The Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          screen.w,screen.h,
                          0)) == NULL) {
        return false;
    }
    Main_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Ball temp(Main_Renderer,"ball2.png",0,0,90000000);
    BallAry.push_back(temp);

/**
* Use this way to load an image onto a texture
*   SDL_Texture* Tex_Test = CTexture::OnLoad("Test.bmp", Main_Renderer);
*    if(Tex_Test == NULL){
*       return false;
*    }
*/

    return true;
}

