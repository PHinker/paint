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
        float width, height;

    public:
        Rectangle( float x = 0.0, float y = 0.0, SelectedColor bc = WHITE, SelectedColor fc = BLACK, float w = 1.0, float h = 1.0 );
        ~Rectangle( );
        void changeDimensions( float w, float h );
        void draw( ) const;
        void erase( ) const;
        void print( ostream& out ) const;
};

#endif

