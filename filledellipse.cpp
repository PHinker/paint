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

// mutator method for Circle class
void FilledEllipse::changeRadius( int rX, int rY )
{
    //  cout << "Change Circle radius from " << radius << " to " << r << endl;
    radiusX = rX;
    radiusY = rY;
}

bool FilledEllipse::containsPoint(int x, int y)
{
    return ((pow(x - locX, 2) / pow(radiusX, 2) + pow(y - locY, 2) / pow(radiusY,
             2)) <= 1.0) ? true : false;
}

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

// must override pure virtual Shape::print() method to instantiate class
void FilledEllipse::print( ostream& out ) const
{
    out << "circle at position (" << locX << "," << locY << ")"
        << " with radius " << radiusX << endl;
}

