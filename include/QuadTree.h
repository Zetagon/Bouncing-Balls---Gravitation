#ifndef QUADTREE_H
#define QUADTREE_H


class QuadTree
{
    public:
        QuadTree();
        virtual ~QuadTree();

        QuadTree Getnode1() { return node1; }
        void Setnode1(QuadTree val) { node1 = val; }
        QuadTree Getnode2() { return node2; }
        void Setnode2(QuadTree val) { node2 = val; }
        QuadTree Getnode3() { return node3; }
        void Setnode3(QuadTree val) { node3 = val; }
        QuadTree Getnode4() { return node4; }
        void Setnode4(QuadTree val) { node4 = val; }
        const int GetMAX_OBJ() { return MAX_OBJ; }
        void SetMAX_OBJ(const int val) { MAX_OBJ = val; }

        QuadTree node1;
        QuadTree node2;
        QuadTree node3;
        QuadTree node4;
        const int MAX_OBJ;

    protected:

    private:
};

#endif // QUADTREE_H
