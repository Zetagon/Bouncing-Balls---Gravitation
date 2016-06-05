#include "QuadTree.h"

QuadTree::QuadTree(int pLevel, SDL_Rect pBounds)
{
    //ctor
    level = pLevel;
    bounds = pBounds;
}

QuadTree::~QuadTree()
{
    //dtor
}

void QuadTree::clear(){
    for (int i = 0; i < nodes.size(); i++) {
        nodes.erase(nodes.begin() + i);
    }
}

void QuadTree::split(){
    int subWidth = (int)((double)bounds.w/2);
    int subHeight = (int)((double)bounds.h/2);
    int x = bounds.x;
    int y = bounds.y;

    SDL_Rect tempRect = {x + subWidth,y , subWidth, subHeight};
    nodes[0] = new QuadTree(level + 1, tempRect);
    tempRect = {x,y,subWidth, subHeight};
    nodes[1] = new QuadTree(level + 1, tempRect);
    tempRect = {x, y + subWidth, subWidth, subHeight};
    nodes[2] = new QuadTree(level + 1, tempRect);
    tempRect = {x + subWidth, y + subHeight, subWidth, subHeight};
    nodes[3] = new QuadTree(level + 1, tempRect);
}

int QuadTree::getIndex(SDL_Rect pRect){
    int index = -1;
    double verticalMidPoint = bounds.x + (bounds.w / 2.0);
    double horizontalMidPoint = bounds.h + (bounds.h / 2.0);

    //Object can fit completely within the top quadrants
    bool topQuadrant = (pRect.y < horizontalMidPoint && pRect.y + pRect.h < horizontalMidPoint);
    //Object can fit completely within the bottom quadrants
    bool bottomQuadrant = (pRect.y > horizontalMidPoint);

    //Object can fit completely within the left quadrants
    if(pRect.x < verticalMidPoint && pRect.x + pRect.w < verticalMidPoint){
        if(topQuadrant){
            index = 1;
        }
        else if (bottomQuadrant){
            index = 2;
        }
    }
    //Object can fit completely within the right quadrants
    else if(pRect.x > verticalMidPoint){
            if(topQuadrant){
                index = 0;
            }
            else if(bottomQuadrant){
                index = 3;
            }
    }

return index;
}
/**
 * Insert the object into the quadtree. If the node
 * exceeds the capacity, it will split and add all
 * objects to their corresponding nodes.
 */
void QuadTree::insertObj(SDL_Rect pRect){
    if(nodes[0] != NULL){

    }
}
