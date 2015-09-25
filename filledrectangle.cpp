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
FilledRectangle::FilledRectangle( float x1, float y1, SelectedColor bc,
                                  SelectedColor fc, float x2, float y2 ) :
    Shape( x1, y1, bc, fc ), x2( x2 ), y2( y2 )
{
}

// destructor
FilledRectangle::~FilledRectangle( )
{
}

// mutator method for FilledRectangle class

// must override pure virtual Shape::draw() method to instantiate class
void FilledRectangle::draw( ) const
{
    DrawFilledRectangle(locX, locY, x2, y2, ColorMap[fillColor]);
    DrawRectangle(locX, locY, x2, y2, ColorMap[borderColor]);
}

void FilledRectangle::move(int centerX, int centerY)
{
    int width, height;
    width = abs(locX - x2);
    height = abs(locY - y2);
    locX = centerX - width / 2;
    locY = centerY - height / 2;
    x2 = centerX + width / 2;
    y2 = centerY + height / 2;
}

int FilledRectangle::getDistanceFromCenter(int clickX, int clickY)
{
    int centerX, centerY, distance;
    centerX = (locX + x2) / 2;
    centerY = (locY + y2) / 2;
    distance = pow(clickX - centerX, 2) + pow(clickY - centerY, 2);
    return distance;
}

// must override pure virtual Shape::erase() method to instantiate class
void FilledRectangle::erase( ) const
{
}

// must override pure virtual Shape::print() method to instantiate class
void FilledRectangle::print( ostream& out ) const
{
}

