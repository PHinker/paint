#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/freeglut.h>
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
 * \brief Screen is a container for all the good stuff.
 *
 * \author Paul and Jake
 *
 * \date Sept. 24, 2015
 *
 */
class Screen
{
private:

    vector<Shape*> shapes;
    SelectedColor borderColor;
    SelectedColor fillColor;
    SelectedShape selectedShape;

public:
    Screen();
    /// This is the function that draws all the shapes in the vector
    void drawShapes();
    /// This handles mouse clicks
    void click(int x, int y, int button);
    /// This handles mouse drag events
    void clickAndDrag(int x, int y, int lastX, int lastY, int button);
    /// This handles keyboard events
    void keyboardAction(unsigned char key, int x, int y);
    /// This draws the static palette
    void initPalette();
};

#endif // SCREEN_H_INCLUDED
