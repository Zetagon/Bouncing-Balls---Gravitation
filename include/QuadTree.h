#ifndef QUADTREE_H
#define QUADTREE_H
#include <SDL.h>
#include <memory>
#include <vector>
struct rectIterator{
    SDL_Rect rect;
    int i;
};
class QuadTree
{
    public:
        QuadTree(int pLevel, SDL_Rect pBounds);
        virtual ~QuadTree();
        void insertObj(SDL_Rect pRect, int pIterator);
        std::vector<rectIterator> retrieve(SDL_Rect pRect);
        std::vector<int> retrieveIterator(SDL_Rect pRect);

        void clear();

        void split();
        int getIndex(SDL_Rect pRect);

        std::vector<std::unique_ptr<QuadTree>> nodes;
        std::vector<rectIterator>  objects;
        SDL_Rect bounds;
        int level;
        int MAX_OBJ =  3;// these are logically const, but can't be const because of compiler reasons
        int MAX_LEVEL = 5;

    protected:

    private:

};

#endif // QUADTREE_H
