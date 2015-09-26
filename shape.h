/**
 * @file shape.h
 *
 * @authors Jake Davidson, Paul Hinker
 *
 * @brief Based on reference code provided by Dr. Weiss for the CSC 300
 *    Data Structures class.
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

/**
 * @class Shape
 *
 * @brief This is an abstract base-class from which all the shapes in the
 * application are derived.  It contains pure virtual functions and so
 * cannot be instantiated.
 *
 * @authors Jake Davidson, Paul Hinker
 */
class Shape
{
protected:                     // note use of protected instead of private
    float locX;                /**< The x-location of the shape */
    float locY;                /**< The y-location of the shape */
    SelectedColor borderColor; /**< Color Enum describing border color */
    SelectedColor fillColor;   /**< Color Enum describing fill color */

public:
    /// constructor
    Shape( float x = 0.0, float y = 0.0, SelectedColor bc = WHITE,
           SelectedColor fc = BLACK);

    /// destructor
    virtual ~Shape( );

    /// Pure virtual member function implemented by derived classes
    /// to aid in selection of the drawn shapes.
    virtual int getDistanceFromCenter(int clickX, int clickY) = 0;

    /// Pure virtual member function that draws the derived shapes.
    virtual void draw() const = 0;

    /// Helper function used to move the shape once it has been selected
    /// by the user with the right-mouse click and drag operation.
    virtual void move(int centerX, int centerY) = 0;

    /// Function used to reposition the shape in the vector of shapes
    /// that are currently being drawn.
    virtual void erase() const = 0;
};

#endif

