#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>
#include <SDL_image.h>
/**
*
*Contains two functions
*   OnLoad loads an image two and SDL_Texture
*   OnDraw "Draws" an SDL_texture to an SDL_Renderer
*
*
*/
class CTexture {
public:
    CTexture();

public:
    static SDL_Texture* OnLoad(char* File, SDL_Renderer* sdlRenderer);
    static SDL_Texture* OnLoadImage(char* File, SDL_Renderer* sdlRenderer);

    static bool OnDraw( SDL_Renderer* sdlRenderer,SDL_Texture* Tex_Src, int x, int y, int w, int h);
    static bool OnDraw( SDL_Renderer* sdlRenderer,SDL_Texture* Tex_Src,SDL_Rect DestR, SDL_Rect SrcR);
    static bool OnDraw( SDL_Renderer* sdlRenderer,SDL_Texture* Tex_Src,SDL_Rect* DestR);



};
#endif // _CSURFACE_H_
