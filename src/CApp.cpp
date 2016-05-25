#include "CApp.h"
#undef main
#include <iostream>
/**
*Constructor to initialize variables
*
*note: the first two lines are necessary
*/
double CApp::SlowMotionValue = 1;
int CApp::scrollModifierX = 0;
int CApp::scrollModifierY = 0;
bool CApp::drawPath = false;
CApp::CApp(){
    Main_Renderer = NULL;
    running = true;
    started = false;
    mouseDown = false;
    rightMouseDown = false;
    drawPath = false;


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



    while(running){
        OnKeyState();
        OnMouseState();
        while (SDL_PollEvent(&Event)){
            OnEvent(Event);
        }
        if(started){
            OnLoop();
        }
            OnRender();
    }
    OnCleanup();

    return 0;
}

double CApp::CalculateDistance(double x, double y, double x1, double y1){
    //Pythagoras theorem to calculate the distance
    return sqrt(pow((x - x1), 2)+ pow((y - y1), 2));
}


int main(int argc, char* argv[]){
    CApp theApp;

    return theApp.OnExecute();

}
