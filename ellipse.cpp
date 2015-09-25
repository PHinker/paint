#include <iostream>
#include <math.h>

using namespace std;

#include "ellipse.h"

// Ellipse class implementation

// constructor
Ellipse::Ellipse( int x, int y, SelectedColor bc, SelectedColor fc, int rX, int rY) : Shape( x, y, bc, fc), radiusX( rX ), radiusY(rY)
{}

// destructor
Ellipse::~Ellipse( )
{}

// mutator method for Circle class
void Ellipse::changeRadius( int rX, int rY )
{
  //  cout << "Change Circle radius from " << radius << " to " << r << endl;
    radiusX = rX;
    radiusY = rY;
}

bool Ellipse::containsPoint(int x, int y)
{
    return ((pow(x-locX, 2) / pow(radiusX, 2) + pow(y-locY,2) / pow(radiusY, 2)) <= 1.0) ? true : false;
}

// must override pure virtual Shape::draw() method to instantiate class
void Ellipse::draw( ) const
{
    DrawEllipse(radiusX, radiusY, locX, locY, ColorMap[borderColor]);

    cout << "Draw Circle: (" <<
         locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", radiusX = " << radiusX << " radiusY = " << radiusY << endl;
}

// must override pure virtual Shape::erase() method to instantiate class
void Ellipse::erase( ) const
{
    //cout << "Erase Circle: (" <<
    //     locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", radius = " << radius << endl;
}

// must override pure virtual Shape::print() method to instantiate class
void Ellipse::print( ostream& out ) const
{
    out << "circle at position (" << locX << "," << locY << ")"
        << " with radius " << radiusX << endl;
}

