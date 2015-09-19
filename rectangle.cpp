/*
                    ***** rectangle.cpp *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the Rectangle class implementation.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

// constructor
Rectangle::Rectangle( float x, float y, SelectedColor c, float w, float h ) :
    Shape( x, y, c ), width( w ), height( h )
{
    cout << "Rectangle constructor: (" <<
         x << "," << y << ") = " << c << ", width " << w << " x height " << h << endl;
}

// destructor
Rectangle::~Rectangle( )
{
    cout << "Rectangle destructor: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

// mutator method for Rectangle class
void Rectangle::changeDimensions( float w, float h )
{
    cout << "Change Rectangle dimensions from " << width << " x " << height << " to " << w << " x " << h << endl;
    width = w;
    height = h;
}

// must override pure virtual Shape::draw() method to instantiate class
void Rectangle::draw( ) const
{
    cout << "Draw  Rectangle: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

// must override pure virtual Shape::erase() method to instantiate class
void Rectangle::erase( ) const
{
    cout << "Erase Rectangle: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

// must override pure virtual Shape::print() method to instantiate class
void Rectangle::print( ostream& out ) const
{
    out << ( width == height ? "square" : "rectangle" ) << " at position (" << locX << "," << locY << ")"
        << " with sides " << width << " and " << height << endl;
}

