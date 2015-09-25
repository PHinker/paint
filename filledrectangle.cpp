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

#include "filledrectangle.h"

// FilledRectangle class implementation

// constructor
FilledRectangle::FilledRectangle( float x, float y, SelectedColor bc, SelectedColor fc, float w, float h ) :
    Shape( x, y, bc, fc ), width( w ), height( h )
{
    cout << "FilledRectangle constructor: (" <<
         x << "," << y << ") = " << bc << ", width " << w << " x height " << h << endl;
}

// destructor
FilledRectangle::~FilledRectangle( )
{
    cout << "FilledRectangle destructor: (" <<
         locX << "," << locY << ") = " << borderColor << ", width " << width << " x height " << height << endl;
}

// mutator method for FilledRectangle class
void FilledRectangle::changeDimensions( float w, float h )
{
    cout << "Change FilledRectangle dimensions from " << width << " x " << height << " to " << w << " x " << h << endl;
    width = w;
    height = h;
}

// must override pure virtual Shape::draw() method to instantiate class
void FilledRectangle::draw( ) const
{
cout << "Draw FilledRectangle: (" <<
         locX << "," << locY << ") = " << borderColor << ", width " << width << " x height " << height << endl;
     DrawFilledRectangle(locX, locY, locX+width, locY+height, ColorMap[fillColor]);
     DrawRectangle(locX, locY, locX+width, locY+height, ColorMap[borderColor]);
}

// must override pure virtual Shape::erase() method to instantiate class
void FilledRectangle::erase( ) const
{
    cout << "Erase FilledRectangle: (" <<
         locX << "," << locY << ") = " << borderColor << ", width " << width << " x height " << height << endl;
}

// must override pure virtual Shape::print() method to instantiate class
void FilledRectangle::print( ostream& out ) const
{
    out << ( width == height ? "square" : "rectangle" ) << " at position (" << locX << "," << locY << ")"
        << " with sides " << width << " and " << height << endl;
}

