#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED

#include "shape.h"

class Ellipse : public Shape
{
    private:
        int radiusX, radiusY;

    public:
        Ellipse( int x = 0.0, int y = 0.0, SelectedColor bc = WHITE, SelectedColor fc = BLACK, int rX = 1.0, int rY = 1.0, bool f = false);
        ~Ellipse( );
        void changeRadius( int rx, int ry );
        bool containsPoint(int x, int y);
        int getCenterX() { return locX ;}
        int getCenterY() { return locY ;}
        void draw( ) const;
        void erase( ) const;
        void print( ostream& out ) const;
};


#endif // ELLIPSE_H_INCLUDED
