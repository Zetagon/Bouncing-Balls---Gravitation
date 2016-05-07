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
                Ball BallTemp(Main_Renderer);
                BallAry.push_back(BallTemp);
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
    SDL_PumpEvents();

}
