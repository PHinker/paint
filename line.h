#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "shape.h"

class Line : public Shape
{
protected:
    int endX, endY;

public:
    Line( int x = 0.0, int y = 0.0, const SelectedColor borderColor = WHITE,
          int xend = 1.0, int yend = 1.0);
    ~Line( );
    void changeDimensions( int w, int h );
    bool containsPoint(int x, int y);
    int getCenterX();
    int getCenterY();
    void draw( ) const;
    void move(int centerX, int centerY);
    int getDistanceFromCenter(int clickX, int clickY);
    void erase( ) const;
    void print( ostream& out ) const;
};

#endif // LINE_H_INCLUDED
