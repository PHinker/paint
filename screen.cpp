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
   {12, GREEN}, {13, DKGREEN}, {14, RED}, {15, DKRED}, {16, BLACK}
};

map<int, SelectedShape> shapeMap =
{
   {16, RECTANGLE}, {17, FLDRECTANGLE}, {18, ELLIPSE}, {19, FLDELLIPSE},
   {20, LINE}, {21, TEXT}
};

extern map<SelectedColor, array<float, 3>> ColorMap;

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

#define ScrToPos(x,y) ((x < 101) ? y/50 * 2 + (x/50) : 23)
#define PosXToScr(x) (x % 2) * 50
#define PosYToScr(y) (y / 2) * 50

//gets called when user clicks in one spot on screen
void Screen::click(int x, int y ) {

    //if the click was within the palette
        int locationIndex = ScrToPos(x, y);
        if (locationIndex > 0 && locationIndex < 16)
           selectedColor = colorIndexMap[locationIndex];

        //If click is a shape
        else if(locationIndex > 15 && locationIndex < 22)
           selectedShape = shapeMap[locationIndex];

        else
        {

        }
        //use switch to assign colors
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex << endl;
        cerr << "selected color = " << selectedColor << " selected shape = " << selectedShape << endl;
}

void Screen::clickAndDrag(int x, int y, int lastX, int lastY){

    //need to create derived shape classes
    //add shapes to vector here

    //not in palette
    int startX = min(x, lastX), startY = min(y, lastY);

    if(ScrToPos(x, y) > 22 && selectedShape != NONE) {
       switch (selectedShape) {
          case LINE:
          case RECTANGLE:
          case ELLIPSE:
          {
    // ToDo : add the selected shape to the shape vector
           Rectangle *rect = new Rectangle(startX, startY, WHITE, BLACK, abs(x-lastX), abs(y-lastY));
           rect->draw();
          }
       }
    }/*
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
*/

}

void Screen::initPalette()
{
    // Statically draw the palette on the left

    for(int i = 0 ; i < 16 ; i++)
        DrawFilledRectangle(PosXToScr(i), PosYToScr(i), PosXToScr(i) + 50, PosYToScr(i) + 50, ColorMap[colorIndexMap[i]]);
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
