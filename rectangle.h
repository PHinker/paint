/*
                    ***** rectangle.h *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the Rectangle class interface.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// guard against multiple inclusions
#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"

// Rectangle class interface
class Rectangle : public Shape
{
private:
    float x2, y2;

public:
    Rectangle( float x1 = 0.0, float y1 = 0.0, SelectedColor bc = WHITE,
               SelectedColor fc = BLACK, float x2 = 1.0, float y2 = 1.0 );
    ~Rectangle( );
    //void changeDimensions( float w, float h );
    void draw( ) const;
    void move(int centerX, int centerY);
    int getDistanceFromCenter(int clickX, int clickY);
    void erase( ) const;
    void print( ostream& out ) const;
};

#endif

