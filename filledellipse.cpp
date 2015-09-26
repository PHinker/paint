#include <iostream>
#include <math.h>

using namespace std;

#include "filledellipse.h"

// Ellipse class implementation

// constructor
FilledEllipse::FilledEllipse( int x, int y, SelectedColor bc, SelectedColor fc,
                              int rX, int rY) : Shape( x, y, bc, fc), radiusX( rX ), radiusY(rY)
{}

// destructor
FilledEllipse::~FilledEllipse( )
{}

// must override pure virtual Shape::draw() method to instantiate class
void FilledEllipse::draw( ) const
{
    DrawFilledEllipse(radiusX, radiusY, locX, locY, ColorMap[borderColor]);
    DrawEllipse(radiusX, radiusY, locX, locY, ColorMap[fillColor]);
}

void FilledEllipse::move(int centerX, int centerY)
{
    locX = centerX;
    locY = centerY;
}

int FilledEllipse::getDistanceFromCenter(int clickX, int clickY)
{
    //center already calced, locX and locY
    int distance;
    distance = pow(clickX - locX, 2) + pow(clickY - locY, 2);
    return distance;
}

// must override pure virtual Shape::erase() method to instantiate class
void FilledEllipse::erase( ) const
{
    //cout << "Erase Circle: (" <<
    //     locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", radius = " << radius << endl;
}
