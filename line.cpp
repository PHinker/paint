#include <iostream>
using namespace std;

#include "line.h"

// Rectangle class implementation

// constructor
Line::Line( int x, int y, const SelectedColor bc, int endx, int endy) :
    Shape( x, y, bc, bc, false ), endX( endx ), endY( endy )
{
    cout << "Line constructor: (" <<
         x << "," << y << ") = " << bc << ", endX " << endx << " endY " << endY << endl;
}

// destructor
Line::~Line( )
{
    cout << "Line destructor: (" <<
         locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", endX " << endX << " endY " << endY<< endl;
}

bool Line::containsPoint(int x, int y)
{
    return (locX <= x && endX >= x && locY <= y && endY >= y);
}

// must override pure virtual Shape::draw() method to instantiate class
void Line::draw( ) const
{
    DrawLine( locX, locY, endX, endY, ColorMap[borderColor] );
    //cout << "Draw  Line: (" <<
    //     locX << "," << locY << ") = " << borderColor << ", endX " << endX << " endY " << endY << endl;
}

// must override pure virtual Shape::erase() method to instantiate class
void Line::erase( ) const
{
    DrawLine(locX, locY, endX, endY, ColorMap[BLACK]);
    cout << "Erase Line: (" <<
         locX << "," << locY << ") = " << borderColor << ", endX " << endX << " endY " << endY << endl;
}

int Line::getCenterX()
{
   return locX + (endX - locX) / 2;
}

int Line::getCenterY()
{
   return locY + (endY - locY) / 2;
}
// must override pure virtual Shape::print() method to instantiate class
void Line::print( ostream& out ) const
{
    out << "Line at position (" << locX << "," << locY << ")"
        << " with end at (" << endX << " and " << endY << ")" << endl;
}