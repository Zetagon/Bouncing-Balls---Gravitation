#include "Circle.h"

Circle::Circle(int r, int a, int b)
{
    //ctor
    radius = r;
    x = a;
    y = b;
}

Circle::~Circle()
{
    //dtor

}

Circle::getX(){
    return x;
}
Circle::getY(){
    return y;
}
Circle::getRadius(){
    return radius;
}
