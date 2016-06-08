#include "CApp.h"
#include "QuadTree.h"
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
    scrollModifierX = screen.w / 2.0;
    scrollModifierY = screen.h / 2.0;

    if((window = SDL_CreateWindow("The Window",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          screen.w,screen.h,
                           0)) == NULL) {
        return false;
    }

    Main_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    pointTex = SDL_CreateTexture(Main_Renderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_TARGET,
                                screen.w * MAX_ZOOM,
                                screen.h * MAX_ZOOM);
    SDL_SetRenderTarget(Main_Renderer, pointTex);
    SDL_SetRenderDrawColor(Main_Renderer,255,255,255,255);
    SDL_RenderClear(Main_Renderer);
    SDL_SetRenderTarget(Main_Renderer, NULL);

    ballTex = SDL_CreateTexture(Main_Renderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_TARGET,
                                screen.w * MAX_ZOOM,
                                screen.h * MAX_ZOOM);
    SDL_SetRenderTarget(Main_Renderer, ballTex);
    SDL_SetRenderDrawColor(Main_Renderer,255,255,255,255);
    SDL_RenderClear(Main_Renderer);
    SDL_SetRenderTarget(Main_Renderer, NULL);

    //initializes the quadtree
    SDL_Rect treeRect = {0,0,screen.w * MAX_ZOOM, screen.h * MAX_ZOOM};
//    QuadTree tempTree(0,treeRect);
//    ballTree = &tempTree;//new QuadTree(0, treeRect);
    ballTree = std::unique_ptr<QuadTree>(new QuadTree(0, treeRect));

    Ball temp(Main_Renderer,"ball2.png");
    temp.mass = 9000;
    temp.x = screen.w / 2.0;
    temp.y = screen.h / 2.0;
    temp.canMove = true;

    BallAry.push_back(temp);

//    temp.mass = 9000;
//    temp.x = 300;
//    temp.y = 400;
//    temp.canMove = false;
//
//
//    BallAry.push_back(temp);


/**
* Use this way to load an image onto a texture
*   SDL_Texture* Tex_Test = CTexture::OnLoad("Test.bmp", Main_Renderer);
*    if(Tex_Test == NULL){
*       return false;
*    }
*/

    return true;
}

