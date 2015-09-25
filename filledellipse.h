#ifndef FILLEDELLIPSE_H_INCLUDED
#define FILLEDELLIPSE_H_INCLUDED

#include "shape.h"

class FilledEllipse : public Shape
{
private:
    int radiusX, radiusY;

public:
    FilledEllipse( int x = 0.0, int y = 0.0, SelectedColor bc = WHITE,
                   SelectedColor fc = BLACK, int rX = 1.0, int rY = 1.0);
    ~FilledEllipse( );
    void changeRadius( int rx, int ry );
    bool containsPoint(int x, int y);
    int getCenterX()
    {
        return locX ;
    }
    int getCenterY()
    {
        return locY ;
    }
    void draw( ) const;
    void move(int centerX, int centerY);
    int getDistanceFromCenter(int clickX, int clickY);
    void erase( ) const;
    void print( ostream& out ) const;
};


#endif // FILLEDELLIPSE_H_INCLUDED
