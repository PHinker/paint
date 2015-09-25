/*
                    ***** shape.h *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the Shape class implementation.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// include files
#include <iostream>
using namespace std;

#include "shape.h"

// Shape class implementation
// Note that this is an abstract class since it contains pure virtual functions.

// constructor
Shape::Shape( float x, float y, SelectedColor bc, SelectedColor fc) :
    locX( x ), locY( y ), borderColor( bc ), fillColor (fc)
{
    cout << "Shape constructor: (" << locX << "," << locY << ") = " << borderColor
         << endl;
}

// destructor
Shape::~Shape( )
{
    cout << "Shape destructor: (" << locX << "," << locY << ") = " << borderColor <<
         endl;
}

// move object
void Shape::moveTo( float x, float y )
{
    cout << "Move Shape from (" << locX << "," << locY << ") to (" << x << "," << y
         << ")" << endl;
    locX = x;
    locY = y;
}

// change color of object
void Shape::changeColor( SelectedColor c )
{
    cout << "Change Shape color from " << borderColor << " to " << c << endl;
    borderColor = c;
}

