#include "CTexture.h"
#include <iostream>
#include <stdio.h>

CTexture::CTexture() {
}
/**
*
*@param  File Filename for the image to load
*@param sdlRenderer the SDL_Renderer which the return texture belongs to
*
*Loads an image to a texture that belongs to sdlRenderer.
*
*
*
*@return An SDL_Texture which the image is loaded on
*/
SDL_Texture* CTexture::OnLoad(char* File, SDL_Renderer* sdlRenderer) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Texture_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(File))==NULL){
        std::cout << "Something went wrong!";
        return NULL;
    }

    Texture_Return = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Temp);
    if(Texture_Return == NULL){
        printf("Error!");
    }
    return Texture_Return;
}
SDL_Texture* CTexture::OnLoadImage(char* File, SDL_Renderer* sdlRenderer) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Texture_Return = NULL;

    if((Surf_Temp = IMG_Load(File))==NULL){
        std::cout << "Something went wrong!";
        return NULL;
    }

    Texture_Return = SDL_CreateTextureFromSurface(sdlRenderer, Surf_Temp);
    if(Texture_Return == NULL){
        printf("Error!");
    }
    return Texture_Return;
}
/**
*
*@param sdlRenderer the SDL_Renderer which Tex_Src is copied to
*@param Tex_Src the SDL_Texture which is copied to sdlRenderer
*@param x   the x coordinate of an SDL_Rect that determines where the texture is copied to
*@param y   the y coordinate of an SDL_Rect that determines where the texture is copied to
*@param w   the width of an SDL_Rect that determines where the texture is copied to
*@param h   the height of an SDL_Rect that determines where the texture is copied to
*
*Draws Tex_Src onto the sdlRenderer
*
*
*@return false if it fails, true if succeeded
*/
bool CTexture::OnDraw( SDL_Renderer* sdlRenderer,  SDL_Texture* Tex_Src, int x, int y, int w, int h){
    if ( Tex_Src == NULL) {
        printf("Failed");
        return false;
    }

    SDL_Rect DestR;
    SDL_Rect SrcR;

    DestR.x = x;
    DestR.y = y;
    DestR.w = w;
    DestR.h = h;

    if (SDL_RenderCopy(sdlRenderer,Tex_Src, NULL, &DestR )!=0){
        printf("REndercopy is not working! The error is: %s \n",SDL_GetError());
    }

    return true;
}

/**
*
*@param sdlRenderer the SDL_Renderer which Tex_Src is copied to
*@param Tex_Src the SDL_Texture which is copied to sdlRenderer
*@param DestR the SDL_Rect which represents the area where Tex_Src is copied to
*@param SrcR the SDL_Rect which represents the area of Tex_Src which will be copied
*
*Draws Tex_Src onto the sdlRenderer
*
*@return false if it fails, true if succeeded
*/
bool CTexture::OnDraw( SDL_Renderer* sdlRenderer,  SDL_Texture* Tex_Src,SDL_Rect DestR, SDL_Rect SrcR){
    if ( Tex_Src == NULL) {
        printf("Failed");
        return false;
    }

    if (SDL_RenderCopy(sdlRenderer,Tex_Src, &SrcR, &DestR )!=0){
        printf("Rendercopy is not working! The error is: %s \n",SDL_GetError());
    }

    return true;
}

/**
*
*@param sdlRenderer the SDL_Renderer which Tex_Src is copied to
*@param Tex_Src the SDL_Texture which is copied to sdlRenderer
*@param DestR the SDL_Rect which represents the area where Tex_Src is copied to
*
*
*Draws Tex_Src onto the sdlRenderer
*note: Everything on Tex_Src will bi copied
*
*@return false if it fails, true if succeeded
*/
bool CTexture::OnDraw( SDL_Renderer* sdlRenderer,  SDL_Texture* Tex_Src, SDL_Rect* DestR){
    if ( Tex_Src == NULL) {
        printf("Failed");
        return false;
    }



    if (SDL_RenderCopy(sdlRenderer,Tex_Src, NULL, DestR )!=0){
        printf("Rendercopy is not working! The error is: %s \n",SDL_GetError());
    }

    return true;
}
