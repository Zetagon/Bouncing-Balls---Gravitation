#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle(int r, int a, int b);
        virtual ~Circle();
        getX();
        getY();
        getRadius();

    protected:

    private:
        int radius;
        int x;
        int y;
};

#endif // CIRCLE_H
