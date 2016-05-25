#include "Point.h"

Point::Point(int pX, int pY)
{
    x = pX;
    y = pY;
}

Point::~Point()
{
    //dtor
}

void Point::renderPoint(SDL_Renderer* renderer){
     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawPoint(renderer, x  + CApp::scrollModifierX, y  + CApp::scrollModifierY);
     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
