#include <cstdlib>
#include <iostream>
#include <map>
#include <array>
#include "screen.h"

using namespace std;

// the GLUT header automatically includes gl.h and glu.h

map<int, SelectedColor> colorIndexMap =
{
   {0, PURPLE}, {1,DKPURPLE}, {2, ORANGE}, {3, DKORANGE}, {4, YELLOW}, {5, DKYELLOW},
   {6, CYAN}, {7, DKCYAN}, {8, MAGENTA}, {9, DKMAGENTA}, {10, BLUE}, {11, DKBLUE},
   {12, GREEN}, {13, DKGREEN}, {14, RED}, {15, DKRED}
};

map<int, SelectedShape> shapeMap =
{
   {16, LINE}, {17, TEXT}, {18, RECTANGLE}, {19, FLDRECTANGLE},
   {20, ELLIPSE}, {21, FLDELLIPSE}
};

map<SelectedColor, array<float, 3>> ColorMap;

Screen::Screen()
{
   ColorMap[BLACK] = array<float, 3>{0.0, 0.0, 0.0};
   ColorMap[RED] = array<float, 3>{ 1.0, 0.0, 0.0 };
   ColorMap[GREEN] = array<float, 3> { 0.0, 1.0, 0.0 };
   ColorMap[BLUE] = array<float, 3> { 0.0, 0.0, 1.0 };
   ColorMap[MAGENTA] = array<float, 3> { 1.0, 0.0, 1.0 };
   ColorMap[CYAN] = array<float, 3> { 0.0, 1.0, 1.0 };
   ColorMap[YELLOW] = array<float, 3> { 1.0, 1.0, 0.0 };
   ColorMap[ORANGE] = array<float, 3> {1.0, 153.0/255.0, 0.0};
   ColorMap[PURPLE] = array<float, 3> {204.0/255.0, 0.0, 204.0/255.0};
   ColorMap[DKBLUE] = array<float, 3> { 0.0, 0.0, 0.5};
   ColorMap[DKRED] = array<float, 3> {0.5, 0.0, 0.0};
   ColorMap[DKGREEN] = array<float, 3> {0.0, 0.5, 0.0};
   ColorMap[DKMAGENTA] = array<float, 3> {0.5, 0.0, 0.5};
   ColorMap[DKCYAN] = array<float, 3> {0.0, 0.5, 0.5};
   ColorMap[DKYELLOW] = array<float, 3> {0.5, 0.5, 0.0};
   ColorMap[DKORANGE] = array<float, 3> {204.0/255.0, 102.0/255.0, 0.0};
   ColorMap[DKPURPLE] = array<float, 3> {102.0/255.0, 0.0, 102.0/255.0};
   ColorMap[WHITE] = array<float, 3> { 1.0, 1.0, 1.0};
}

//gets called when user clicks in one spot on screen
void Screen::click(int x, int y ) {

    //if the click was within the palette
        int locationIndex = (y/50) * 2 + (x/50);
        if (locationIndex > 0 && locationIndex < 16)
           selectedColor = colorIndexMap[locationIndex];

        //If click is a shape
        else if(locationIndex > 15 && locationIndex < 22)
           selectedShape = shapeMap[locationIndex];

        //use switch to assign colors
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex << endl;
}

void Screen::clickAndDrag(int x, int y, int lastX, int lastY){

    //need to create derived shape classes
    //add shapes to vector here

    //not in palette
    if(x > 100 && selectedShape != NONE && lastX > 100) {
        if(selectedShape == LINE)
            DrawLine(x, y, lastX, lastY, ColorMap[selectedColor]);
        if(selectedShape == RECTANGLE)
            DrawRectangle(x, y, lastX, lastY, ColorMap[selectedColor]);
        if(selectedShape == FLDRECTANGLE)
            DrawFilledRectangle(x, y, lastX, lastY, ColorMap[selectedColor]);
        if(selectedShape == ELLIPSE)
            DrawEllipse(abs(lastX - x)/2, abs(lastY - y)/2, lastX, lastY, ColorMap[selectedColor]);
        if(selectedShape == FLDELLIPSE)
            DrawFilledEllipse(abs(lastX - x), abs(lastY - y), lastX, lastY, ColorMap[selectedColor]);
    }

}

void Screen::initPalette()
{
    // Statically draw the palette on the left

    DrawFilledRectangle(0, 0, 50, 50, ColorMap[RED]);
    DrawFilledRectangle(50, 0, 100, 50, ColorMap[DKRED]);
    DrawFilledRectangle(0, 50, 50, 100, ColorMap[GREEN]);
    DrawFilledRectangle(50, 50, 100, 100, ColorMap[DKGREEN]);
    DrawFilledRectangle(0, 100, 50, 150, ColorMap[BLUE]);
    DrawFilledRectangle(50, 100, 100, 150, ColorMap[DKBLUE]);
    DrawFilledRectangle(0, 150, 50, 200, ColorMap[MAGENTA]);
    DrawFilledRectangle(50, 150, 100, 200, ColorMap[DKMAGENTA]);
    DrawFilledRectangle(0, 200, 50, 250, ColorMap[CYAN]);
    DrawFilledRectangle(50, 200, 100, 250, ColorMap[DKCYAN]);
    DrawFilledRectangle(0, 250, 50, 300, ColorMap[YELLOW]);
    DrawFilledRectangle(50, 250, 100, 300, ColorMap[DKYELLOW]);
    DrawFilledRectangle(0, 300, 50, 350, ColorMap[ORANGE]);
    DrawFilledRectangle(50, 300, 100, 350, ColorMap[DKORANGE]);
    DrawFilledRectangle(0, 350, 50, 400, ColorMap[PURPLE]);
    DrawFilledRectangle(50, 350, 100, 400, ColorMap[DKPURPLE]);
}

void Screen::keyboardAction(unsigned char key, int x, int y) {

    switch ( key )
    {
        // Escape quits program
	case 'q':
	case EscapeKey:
	    exit( 0 );
	    break;

        // anything else redraws window
	default:
	    glutPostRedisplay();
	    break;
    }

}
