/**
 * \file rectangle.h
 *
 * @author : Jake and Paul
 *
 * \brief : Based on reference code provided by Dr. Weiss for the CSC 300 -
 *    Data Structures class.
*/

// guard against multiple inclusions
#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"

/**
 * \class Rectangle
 *
 * \brief The class to draw, select, and move a rectangle for the csc300 -
 *    Program 1 programming assignment.
 *
 * \authors : Jake and Paul
 */
class Rectangle : public Shape
{
private:
    float x2, y2;

public:
    /// Constructor
    Rectangle( float x1 = 0.0, float y1 = 0.0, SelectedColor bc = WHITE,
               SelectedColor fc = BLACK, float x2 = 1.0, float y2 = 1.0 );

    /// Destructor
    ~Rectangle( );

    /// Implementation of the Shape class's pure virtual draw function.
    /// Used to render the rectangle on the screen.
    void draw( ) const;

    /// Helper function used to reposition the shape on the screen after
    /// the user has selected it with a right-mouse click and dragged it
    /// to a new position.
    void move(int centerX, int centerY);

    /// Helper function to aid in the selection (with the right-mouse)
    /// of this shape.
    int getDistanceFromCenter(int clickX, int clickY);

    /// Function to reposition the shape in the shapes vector which
    /// causes it to be rendered last and thus on top of any other
    /// shapes that are in the vector.
    void erase( ) const;
};

#endif
