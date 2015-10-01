/*************************************************************************//**
 * @file
 *
 * @author Jake Davidson
 * @author Paul Hinker
 *
 * @brief Based on reference code provided by Dr. Weiss for 
 *    CSC 300 - Data Structures
 */

// guard against multiple inclusions
#ifndef _FilledRectangle_H_
#define _FilledRectangle_H_

#include "shape.h"

/**
 * @class FilledRectangle
 *
 * @brief The class to draw, select, and move a filled rectangle for the
 *    csc300 - Program 1 programming assignment.
 *
 * @author Jake Davidson
 * @author Paul Hinker
 */
class FilledRectangle : public Shape
{
private:
    float x2, y2;

public:
    /// Constructor
    FilledRectangle( float x1 = 0.0, float y1 = 0.0, SelectedColor bc = WHITE,
                     SelectedColor fc = BLACK, float x2 = 1.0, float y2 = 1.0 );
    /// Destructor
    ~FilledRectangle( );

    /// Inherited class implementation of the base class pure virtual function
    /// to draw the filled rectangle shape.
    void draw( ) const;

    /// A member function used to reposition the filled rectangle after
    /// selection and drag by the user (using the right mouse)
    void move(int centerX, int centerY);

    /// A helper function to aid in deciding if this shape was the nearest
    /// one to a right-click mouse event.
    int getDistanceFromCenter(int clickX, int clickY);

    /// A helper function to reposition the shape to the front of the draw
    /// screen (by making it drawn last)
    void erase( ) const;
};

#endif

