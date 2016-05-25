#include "CApp.h"

void CApp::OnScroll(int x, int y){
    scrollModifierX += x;
    scrollModifierY += y;
}
