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

    }
}

void CApp::OnKeyState() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);


    SDL_PumpEvents();

}
