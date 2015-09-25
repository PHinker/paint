/*
                    ***** shape.h *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the Shape class interface.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

//-----------------------------------------------------------------------

// guard against multiple inclusions
#ifndef _Shape_H_
#define _Shape_H_

// include files
#include <iostream>
#include <cmath>
#include "globals.h"
#include "graphics.h"


using namespace std;

//-----------------------------------------------------------------------

// Shape class interface
// Note that this is an abstract class since it contains pure virtual functions.
class Shape
{
protected:                    // note use of protected instead of private
    float locX, locY;
    SelectedColor borderColor, fillColor;

public:                       // public methods
    // constructor
    Shape( float x = 0.0, float y = 0.0, SelectedColor bc = WHITE,
           SelectedColor fc = BLACK);

    // destructor
    virtual ~Shape( );

    // move object
    void moveTo( float x, float y );

    // change color of object
    void changeColor( SelectedColor c );

    // print, draw and erase methods:
    // pure virtual methods that must be overridden in non-abstract derived classes
    virtual int getDistanceFromCenter(int clickX, int clickY) = 0;
    virtual void print( ostream& ) const = 0;
    virtual void draw() const = 0;
    virtual void move(int centerX, int centerY) = 0;
    virtual void erase() const = 0;
};

#endif

