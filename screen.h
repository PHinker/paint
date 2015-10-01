/*************************************************************************//**
* @file
*****************************************************************************/
#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <cstdlib>
#include <iostream>
#include <map>
#include <array>
#include "graphics.h"
#include "util.h"
#include "globals.h"
#include "shape.h"
#include "rectangle.h"
#include "line.h"
#include "ellipse.h"
#include "filledellipse.h"
#include "filledrectangle.h"

/**
 * \class Screen
 *
 * Container class that holds all information about the canvas,
 * palette, and user selections on it. It uses enumerated types
 * to keep track of user selections for fill color, border color
 * and the selected shape. When the user clicks, drags, or types,
 * the OpenGL callback functions and their data are routed into this
 * class.
 *
 * \author Paul Hinker, Jake Davidson
 *
 */
class Screen
{
private:
    //holds pointers to all shapes drawn to screen
    vector<Shape*> shapes;
    //choices of shapes and colors the user has made
    SelectedColor borderColor;
    SelectedColor fillColor;
    SelectedShape selectedShape;

    //maps enum of colors to integers so they
    //can be used as array indecies to the color float arrays
    map<int, SelectedColor> colorIndexMap =
{
    {0, PURPLE}, {1, DKPURPLE}, {2, ORANGE}, {3, DKORANGE}, {4, YELLOW},
    {5, DKYELLOW}, {6, CYAN}, {7, DKCYAN}, {8, MAGENTA}, {9, DKMAGENTA},
    {10, BLUE}, {11, DKBLUE}, {12, GREEN}, {13, DKGREEN}, {14, RED},
    {15, DKRED}, {16, BLACK}
};

//Maps shape enums to integers so they can be used as array indicies
map<int, SelectedShape> shapeMap =
{
    {16, RECTANGLE}, {17, FLDRECTANGLE}, {18, ELLIPSE}, {19, FLDELLIPSE},
    {20, LINE}, {21, TEXT}
};

public:
    //constructor, does not take in any paramaters
    Screen();
    //draws shapes from vector to screen
    void drawShapes();
    //handles user click on the canvas and palette
    void click(int x, int y, int button);
    //handles a click and drag on the canvas with right or left mouse button
    void clickAndDrag(int x, int y, int lastX, int lastY, int button);
    //handles keyboard events by the user
    void keyboardAction(unsigned char key, int x, int y);
    //draws palette to screen
    void initPalette();
};

#endif // SCREEN_H_INCLUDED
