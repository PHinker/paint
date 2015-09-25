/*
                    ***** rectangle.h *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the FilledRectangle class interface.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// guard against multiple inclusions
#ifndef _FilledRectangle_H_
#define _FilledRectangle_H_

#include "shape.h"

// FilledRectangle class interface
class FilledRectangle : public Shape
{
    private:
        float width, height;

    public:
        FilledRectangle( float x = 0.0, float y = 0.0, SelectedColor bc = WHITE, SelectedColor fc = BLACK, float w = 1.0, float h = 1.0 );
        ~FilledRectangle( );
        void changeDimensions( float w, float h );
        void draw( ) const;
        void erase( ) const;
        void print( ostream& out ) const;
};

#endif

