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
    objects.clear();
    if(!nodes.empty()){
        for (int i = 0; i < nodes.size(); i++) {
         // nodes.erase(nodes.begin() + i);
        }
    }
   nodes.clear();

}

void QuadTree::split(){
    int subWidth = (int)((double)bounds.w/2);
    int subHeight = (int)((double)bounds.h/2);
    int x = bounds.x;
    int y = bounds.y;

    SDL_Rect tempRect = {x + subWidth,y , subWidth, subHeight};
//    QuadTree tempTree(level+1, tempRect);
    nodes.push_back(std::unique_ptr<QuadTree>(new QuadTree(level + 1, tempRect)));
    tempRect = {x,y,subWidth, subHeight};
//  QuadTree tempTree1(level+1, tempRect);
    nodes.push_back(std::unique_ptr<QuadTree>(new QuadTree(level + 1, tempRect)));
    tempRect = {x, y + subWidth, subWidth, subHeight};
   // QuadTree tempTree2(level+1, tempRect);
    nodes.push_back(std::unique_ptr<QuadTree>(new QuadTree(level + 1, tempRect)));
    tempRect = {x + subWidth, y + subHeight, subWidth, subHeight};
 //   QuadTree tempTree3(level+1, tempRect);
    nodes.push_back(std::unique_ptr<QuadTree>(new QuadTree(level + 1, tempRect)));
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
void QuadTree::insertObj(SDL_Rect pRect, int pIterator){
    rectIterator rectI;
    rectI.rect = pRect;
    rectI.i = pIterator;
    if(!nodes.empty() && nodes.size() <= 4){
        int index = getIndex(rectI.rect);

        if(index != -1){
            nodes[index]->insertObj(rectI.rect, rectI.i);

            return;
        }
    }
//    std::unique_ptr<Ball> tempBall(&pBall);

    objects.push_back(rectI);

    if(objects.size() > MAX_OBJ && level < MAX_LEVEL){
        if(nodes.empty()){
            split();
        }

        int i = 0;
        while(i < objects.size()){
            int index = getIndex(pRect);
            if(index != -1){
//                Ball* tempObj = objects.at(i);
//                std::unique_ptr<Ball> tempObj(std::move(objects.at(i)));

                nodes[index]->insertObj(objects.at(i).rect, objects.at(i).i);
                objects.erase(objects.begin() + i);
            }
            else{
                i++;
            }
        }
    }
}
/**
 * Return all objects that could collide with the given object in the form of a vector
 */
std::vector<rectIterator> QuadTree::retrieve(SDL_Rect pRect){
    int index = getIndex(pRect);
    std::vector<rectIterator> rectI;
    if(index != -1 && !nodes.empty() && nodes.size() <= 4){
       rectI =  nodes[index]->retrieve(pRect);
    }

    rectI.insert(rectI.end(), objects.begin(),objects.end());

    return rectI;
}

std::vector<int> QuadTree::retrieveIterator(SDL_Rect pRect){
    std::vector<int> returnInts;
    std::vector<rectIterator> pRectIterator = retrieve(pRect);
    for(int x = 0; x < pRectIterator.size() ;  x++){
       returnInts.push_back(pRectIterator.at(x).i);
    }
    return returnInts;
}
