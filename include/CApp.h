#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <cmath>

#include "CTexture.h"
#include "Ball.h"
/**
*
*This is a template. Use it to make games with SDL
*
*
*Declare any variables here, and initialize them in the constructor
*
*
*
*/
class CApp {
private:
    bool    running;
    SDL_Renderer* Main_Renderer;
    SDL_Window* window;



public:
    CApp();

    int OnExecute();

        static SDL_Rect screen;

public:
     std::vector<class Ball> BallAry;


    bool OnInit();

    void OnEvent(SDL_Event Event);
    void OnKeyState();

    void OnLoop();

    void OnRender();

    void OnCleanup();
};


#endif
