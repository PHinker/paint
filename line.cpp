#include <iostream>
using namespace std;

#include "line.h"

// Rectangle class implementation

// constructor
Line::Line( int x, int y, const SelectedColor bc, int endx, int endy) :
    Shape( x, y, bc, bc), endX( endx ), endY( endy )
{
    cout << "Line constructor: (" <<
         x << "," << y << ") = " << bc << ", endX " << endx << " endY " << endY << endl;
}

// destructor
Line::~Line( )
{
    cout << "Line destructor: (" <<
         locX << "," << locY << ") = " << borderColor << ", " << fillColor << ", endX "
         << endX << " endY " << endY << endl;
}

// must override pure virtual Shape::draw() method to instantiate class
void Line::draw( ) const
{
    DrawLine( locX, locY, endX, endY, ColorMap[borderColor] );
}

void Line::move(int centerX, int centerY)
{
    int width = abs(locX - endX);
    int height = abs(locY - endY);
    locX = centerX - width / 2;
    locY = centerY + height / 2;
    endX = centerX + width / 2;
    endY = centerY - height / 2;
}

int Line::getDistanceFromCenter(int clickX, int clickY)
{
    int centerX, centerY, distance;
    centerX = abs(locX + endX) / 2;
    centerY = abs(locY + endY) / 2;
    distance = pow(clickX - centerX, 2) + pow(clickY - centerY, 2);
    return distance;
}

// must override pure virtual Shape::erase() method to instantiate class
void Line::erase( ) const
{
    DrawLine(locX, locY, endX, endY, ColorMap[BLACK]);
    cout << "Erase Line: (" <<
         locX << "," << locY << ") = " << borderColor << ", endX " << endX << " endY " <<
         endY << endl;
}

int Line::getCenterX()
{
    return locX + (endX - locX) / 2;
}

int Line::getCenterY()
{
    return locY + (endY - locY) / 2;
}
