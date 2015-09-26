/** @file ellipse.cpp
 * @brief This is the implementation of the ellipse derived class
 *
 * @author Paul Hinker
 * @author Jake Davidson
 * @bug No known bugs
 */

#include <iostream>
#include <math.h>

using namespace std;

#include "ellipse.h"

/** @brief ellipse constructor
 *
 *
 * An ellipse object is constructed when the user has chosen to draw an
 * unfilled ellipse shape.
 *
 * @param x the x-coordinate of where to place the shape
 * @param y the y-coordinate of where to place the shape
 * @param bc a SelectedColor enum specifying the border color
 * @param fc a SelectedColor enum specifying the fill color (not used)
 * @param rX the radius for the x-axis
 * @param rY the radius for the y-axis
 * @return NA
 */
Ellipse::Ellipse( int x, int y, SelectedColor bc, SelectedColor fc, int rX,
                  int rY) : Shape( x, y, bc, fc), radiusX( rX ), radiusY(rY)
{}

// destructor
Ellipse::~Ellipse( )
{}

// must override pure virtual Shape::draw() method to instantiate class
void Ellipse::draw( ) const
{
    DrawEllipse(radiusX, radiusY, locX, locY, ColorMap[borderColor]);
    cout << "Draw Circle: (" <<
         locX << "," << locY << ") = " << borderColor << ", " << fillColor <<
         ", radiusX = " << radiusX << " radiusY = " << radiusY << endl;
}

void Ellipse::move(int centerX, int centerY)
{
    locX = centerX;
    locY = centerY;
}


int Ellipse::getDistanceFromCenter(int clickX, int clickY)
{
    int distance;
    distance = pow(clickX - locX, 2) + pow(clickY - locY, 2);
    return distance;
}

// must override pure virtual Shape::erase() method to instantiate class
void Ellipse::erase( ) const
{
    //cout << "Erase Circle: (" <<
    //     locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", radius = " << radius << endl;
}
