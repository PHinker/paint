#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "shape.h"

/**
 * \class Line
 *
 * \brief The class to draw, select, and move a line for the
 *   csc300 - Program 1 programming assignment.
 *
 * \authors : Jake and Paul
 **/

class Line : public Shape
{
protected:
    int endX;      /**< X-endpoint for the line
    int endY;      /**< Y-endpoint for the line

public:
    /// Constructor
    Line( int x = 0.0, int y = 0.0, const SelectedColor borderColor = WHITE,
          int xend = 1.0, int yend = 1.0);
    /// Destructor
    ~Line( );

    /// Returns the x-center of the line
    int getCenterX()
    {   
        return locX + (endX - locX) / 2;
    }

    /// Returns the y-center of the line
    int Line::getCenterY()
    {   
        return locY + (endY - locY) / 2;
    }

    /// The Line class's implementation of the base class (Shape) pure
    /// virtual function draw().  Used to render the line.
    void draw( ) const;

    /// Helper function to reposition the line after the user has selected
    /// it with a right-mouse click and dragged it to a new position.
    void move(int centerX, int centerY);

    /// Helper function to aid in the selection of the object on the screen.
    int getDistanceFromCenter(int clickX, int clickY);

    /// Function used to reposition the object to the front (i.e. last) 
    /// shape to be drawn which puts it on the top of the rendered image
    void erase( ) const;
};

#endif // LINE_H_INCLUDED
