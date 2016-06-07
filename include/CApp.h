#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
//#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory>


#include "CTexture.h"
#include "Ball.h"
#include "Circle.h"
#include "Timer.h"
#include "QuadTree.h"
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
    bool    started;
    bool    mouseDown;
    bool    rightMouseDown;

    SDL_Renderer* Main_Renderer;
    SDL_Window* window;
    Timer fpsTimer;
    const double GRAVITATION_CONSTANT = 0.66743;



public:
    CApp();

    int OnExecute();

        static SDL_Rect screen;
        static double SlowMotionValue;
        static int scrollModifierX;
        static int scrollModifierY;
        static bool drawPath;
        double zoomModifier;
        const double MAX_ZOOM = 3;
        SDL_Texture* pointTex;//The texture to draw points where the balls have been
        SDL_Texture* ballTex;//The texture to draw the balls
        std::unique_ptr<QuadTree> ballTree ;



public:
     std::vector<class Ball> BallAry;


    bool OnInit();

    void OnEvent(SDL_Event Event);
    void OnKeyState();
    void OnMouseState();

    void OnLoop();

    void OnRender();

    void OnCleanup();

    bool DetectCircleCollision(Circle c1, Circle c2);

    double CalculateDistance(double x, double y, double x1, double y1);

    int GravitationBetweenObj(Ball& ballOne,  Ball& ballTwo);

    void OnScroll(int x, int y);




};

#endif
