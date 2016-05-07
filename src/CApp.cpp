#include "CApp.h"
#undef main
#include <iostream>
/**
*Constructor to initialize variables
*
*note: the first two lines are necessary
*/
CApp::CApp(){
    Main_Renderer = NULL;
    running = true;
}
/**
*
*The main method of the program
*
*@return 0 if succesfull, -1 if not
*/

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;
    Ball ball(Main_Renderer);



    while(running){
        OnKeyState();
        while (SDL_PollEvent(&Event)){
            OnEvent(Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]){
    CApp theApp;

    return theApp.OnExecute();
}
