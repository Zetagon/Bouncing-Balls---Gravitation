#include "Ball.h"

Ball::Ball()
{
    SDL_GetMouseState( &coordinate.x, &coordinate.y );

}
