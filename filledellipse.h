#ifndef FILLEDELLIPSE_H_INCLUDED
#define FILLEDELLIPSE_H_INCLUDED

/**
 * @file filledellipse.h
 *
 * @author : Jake and Paul
 *
 * @brief Based on reference code provided by Dr. Weiss for
 *    CSC 300 - Data Structures
 */

#include "shape.h"

/**
 * \class FilledEllipse
 *
 * \brief The class to draw, select, and move a filled ellipse for the
 *    csc300 - Program 1 programming assignment.
 *
 * \authors : Jake and Paul
 */

class FilledEllipse : public Shape
{
private:
    int radiusX, radiusY;

public:
    /// Constructor expecting x,y location, border and fill color and
    /// an x and y radius to draw and ellipse
    FilledEllipse( int x = 0.0, int y = 0.0, SelectedColor bc = WHITE,
                   SelectedColor fc = BLACK, int rX = 1.0, int rY = 1.0);

    /// Class destructor
    ~FilledEllipse( );

    /// Returns the x-center of the ellipse to support selecting
    int getCenterX()
    {
        return locX ;
    }

    /// Returns the y-center of the ellipse to support selecting
    int getCenterY()
    {
        return locY ;
    }

    /// This is the implementation of the base class's pure virtual
    /// draw function callable on the object.
    void draw( ) const;

    /// A member function used to support moving the object if it is
    /// selected by the user's right mouse click.
    void move(int centerX, int centerY);
  
    /// A helper function to aid in deciding which object was right-
    /// clicked for selection.
    int getDistanceFromCenter(int clickX, int clickY);

    /// Used to remove an object from the list of drawn shapes and
    /// promote it to the front of the drawing vector.
    void erase( ) const;
};


#endif // FILLEDELLIPSE_H_INCLUDED
