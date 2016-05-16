#include "CApp.h"
/**
*
*Handles all events e.g. mouse movements, key presses etc.
*
*
*/
void CApp::OnEvent(SDL_Event Event) {

    switch(Event.type)
    {
case SDL_QUIT:
    running = false;
break;
case SDL_MOUSEBUTTONDOWN:
        switch (Event.button.button)
        {
            case SDL_BUTTON_LEFT:
                {
              //for(int i = 0; i < 10; i++){
                    Ball tempBall(Main_Renderer, "Ball2.png",0, 1, 10);
                    BallAry.push_back(tempBall);
              // }
            break;
                }
            case SDL_BUTTON_RIGHT:
                {
            Ball negBall(Main_Renderer, "Ball2.png",0, -1, -10);
            BallAry.push_back(negBall);
                }

            break;
        }
break;
    }

}

void CApp::OnKeyState() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_ESCAPE]){
        running = false;
    }
    if(keystates[SDL_SCANCODE_RIGHT]){
        for(int i = 0   ; i < BallAry.size(); i++){
                    BallAry[i].ApplyForce(0.01,0);
            }
    }
    if(keystates[SDL_SCANCODE_LEFT]){
        for(int i = 0   ; i < BallAry.size(); i++){
                    BallAry[i].ApplyForce(-0.01,0);
            }
    }
    if(keystates[SDL_SCANCODE_UP]){
        for(int i = 0   ; i < BallAry.size(); i++){
                    BallAry[i].ApplyForce(0,-0.005*10);
            }
    }

     if(keystates[SDL_SCANCODE_DOWN]){
        for(int i = 0   ; i < BallAry.size(); i++){
                    BallAry[i].ApplyForce(0,0.01);
            }
    }
    if(keystates[SDL_SCANCODE_RETURN]){
        started = true;
    }
    if (keystates[SDL_SCANCODE_SPACE]){
        SlowMotionValue = 0.1;
    }
    else{
         SlowMotionValue = 1;
    }

    SDL_PumpEvents();

}
