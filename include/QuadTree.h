#ifndef QUADTREE_H
#define QUADTREE_H
#include <SDL.h>
#include "Ball.h"
class QuadTree
{
    public:
        QuadTree(int pLevel, SDL_Rect pBounds);
        virtual ~QuadTree();
        void insertObj(SDL_Rect pRect);


        void clear();


    protected:

    private:
        void split();
        int getIndex(SDL_Rect pRect);

        std::vector<QuadTree*> nodes;
        std::vector<Ball*>  objects;
        SDL_Rect bounds;
        int level;
        const int MAX_OBJ =  10;
        const int MAX_LEVEL = 5;
};

#endif // QUADTREE_H
