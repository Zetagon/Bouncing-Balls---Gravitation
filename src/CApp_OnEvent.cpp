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
             // for(int i = 0; i < 10; i++){
//                    SDL_Point tempPoint;
//                    SDL_GetMouseState( &tempPoint.x, &tempPoint.y );
//                    Ball tempBall(Main_Renderer, "Ball2.png");
//                    BallAry.push_back(tempBall);
             // }
            break;
                }
            case SDL_BUTTON_RIGHT:
                {
                    SDL_Point tempPoint;
                    SDL_GetMouseState( &tempPoint.x, &tempPoint.y );
                    Ball negBall(Main_Renderer, "BlueBall.png");
                    negBall.mass = -100;
                    negBall.x = tempPoint.x;
                    negBall.y = tempPoint.y;
                    BallAry.push_back(negBall);
                }

            break;
        }
break;
            case SDL_MOUSEWHEEL:

                zoomModifier += Event.wheel.y/100.0;
                if(zoomModifier < 0) zoomModifier = 0;
//                if(zoomModifier > MAX_ZOOM)zoomModifier = 2.0;
                std::cout << zoomModifier << "\n";
            break;
    }

}
void CApp::OnMouseState(){
    int x = 0;
    int y = 0;
    if(SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT)){

        mouseDown = true;
        Ball NewBall(Main_Renderer, "ball2.png");
        //adapts the balls x coordinate to fit the screen when zooming, not finished
//        double percX =  (double)(screen.w + (screen.w * zoomModifier))/screen.w;
//        double percY =  (double)(screen.h + (screen.h * zoomModifier)) / screen.h;
//        x = (double)x * percX;
//        y = (double)y * percY;

        NewBall.x = x - scrollModifierX;
        NewBall.y = y - scrollModifierY;
        NewBall.RenderBall(Main_Renderer, pointTex, ballTex);
        SDL_RenderPresent(Main_Renderer);
        int deltaX;
        int deltaY;
        double vX;
        double vY;
        while(mouseDown){
            if(SDL_GetMouseState(&deltaX,&deltaY) & (SDL_BUTTON(SDL_BUTTON_LEFT))){
                    mouseDown = true;
            }
            else{
                mouseDown = false;
            }
                std::cout << "mouse down";
            deltaX -= x;
            deltaY -= y;
            double distance = sqrt(pow(deltaX,2) + pow(deltaY,2));
            double angle;
            if(deltaX != 0){
                angle = atan(deltaY / deltaX);
            }
             vX = cos(angle) * distance / 50;
             vY = sin(angle) * distance / 50;

            SDL_PumpEvents();
        }
        if(deltaX < 0){
                vX *= -1;
                vY *= -1;
        }
//        NewBall.x = x;
//        NewBall.y = y;
        NewBall.mass = 100;



        NewBall.velocityX = -vX;
        NewBall.velocityY = -vY;
        std::cout << NewBall.velocityY << "\n";
        BallAry.push_back(NewBall);


    }

//    if(SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_RIGHT)){
//
//        rightMouseDown = true;
//        Ball NewBall(Main_Renderer, "blueBall.png");
//        int deltaX;
//        int deltaY;
//        double velocityX;
//        double velocityY;
//        while(rightMouseDown){
//            if(SDL_GetMouseState(&deltaX,&deltaY) & (SDL_BUTTON(SDL_BUTTON_RIGHT))){
//                    rightMouseDown = true;
//            }
//                rightMouseDown = false;
//            }
//                std::cout << "mouse down";
//            deltaX -= x;
//            deltaY -= y;
//            double distance = sqrt(pow(deltaX,2) + pow(deltaY,2));
//            double angle;
//            if(deltaX != 0){
//                angle = atan(deltaY / deltaX);
//            }
//             velocityX = cos(angle) * distance / 100;
//             velocityY = sin(angle) * distance / 100;
//
//            SDL_PumpEvents();
//        }
//        if(deltaX < 0){
//                velocityX *= -1;
//                velocityY *= -1;
//        }
//        NewBall.x = x;
//        NewBall.y = y;
//        NewBall.mass = -10;
//        NewBall.velocityX = -velocityX;
//        NewBall.velocityY = -velocityY;
//        BallAry.push_back(NewBall);
//    }
}

void CApp::OnKeyState() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_ESCAPE]){
        running = false;
    }
    if(keystates[SDL_SCANCODE_D]){
        OnScroll(-10,0);
    }
    if(keystates[SDL_SCANCODE_A]){
        OnScroll(10,0);
    }
    if(keystates[SDL_SCANCODE_W]){
        OnScroll(0,10);
    }

     if(keystates[SDL_SCANCODE_S]){
        OnScroll(0,-10);
    }
    if(keystates[SDL_SCANCODE_RETURN]){
        started = true;
        std::cout << started;
    }

    if (keystates[SDL_SCANCODE_SPACE]){
        SlowMotionValue = 0.1;
    }
    else{
         SlowMotionValue = 1;
    }
    if(keystates[SDL_SCANCODE_TAB]){
        drawPath = true;
    }
    else{
        drawPath = false;
    }
    if(keystates[SDL_SCANCODE_BACKSPACE]){
        for(int i = 0; i < BallAry.size(); i++){
            BallAry.erase(BallAry.begin() + i);
        }
    }

    SDL_PumpEvents();

}
