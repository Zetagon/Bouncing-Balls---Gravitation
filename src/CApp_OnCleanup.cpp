#include "CApp.h"
/**
*Clean up SDL_renderer, windows, surfaces, texture etc.
*
*
*
*
*/
void CApp::OnCleanup(){
    SDL_DestroyRenderer(Main_Renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
