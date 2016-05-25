#ifndef POINT_H
#define POINT_H
#include "CApp.h"

class Point
{
    public:
        Point(int pX,int pY);
        virtual ~Point();

        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        void renderPoint(SDL_Renderer* renderer);

    protected:

    private:
        int x;
        int y;
};

#endif // POINT_H
