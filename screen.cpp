#include <cstdlib>
#include <iostream>
#include <map>
#include <array>
#include "screen.h"

using namespace std;

/** @file screen.cpp
 *
 * @author : Paul
 *
 * @date : Today
 */
// the GLUT header automatically includes gl.h and glu.h

map<int, SelectedColor> colorIndexMap =
{
    {0, PURPLE}, {1, DKPURPLE}, {2, ORANGE}, {3, DKORANGE}, {4, YELLOW},
    {5, DKYELLOW}, {6, CYAN}, {7, DKCYAN}, {8, MAGENTA}, {9, DKMAGENTA},
    {10, BLUE}, {11, DKBLUE}, {12, GREEN}, {13, DKGREEN}, {14, RED},
    {15, DKRED}, {16, BLACK}
};

map<int, SelectedShape> shapeMap =
{
    {16, RECTANGLE}, {17, FLDRECTANGLE}, {18, ELLIPSE}, {19, FLDELLIPSE},
    {20, LINE}, {21, TEXT}
};

Screen::Screen()
{
    ColorMap[BLACK] = array<float, 3> {0.0, 0.0, 0.0};
    ColorMap[RED] = array<float, 3> { 1.0, 0.0, 0.0 };
    ColorMap[GREEN] = array<float, 3> { 0.0, 1.0, 0.0 };
    ColorMap[BLUE] = array<float, 3> { 0.0, 0.0, 1.0 };
    ColorMap[MAGENTA] = array<float, 3> { 1.0, 0.0, 1.0 };
    ColorMap[CYAN] = array<float, 3> { 0.0, 1.0, 1.0 };
    ColorMap[YELLOW] = array<float, 3> { 1.0, 1.0, 0.0 };
    ColorMap[ORANGE] = array<float, 3> {1.0, 153.0 / 255.0, 0.0};
    ColorMap[PURPLE] = array<float, 3> {204.0 / 255.0, 0.0, 204.0 / 255.0};
    ColorMap[DKBLUE] = array<float, 3> { 0.0, 0.0, 0.5};
    ColorMap[DKRED] = array<float, 3> {0.5, 0.0, 0.0};
    ColorMap[DKGREEN] = array<float, 3> {0.0, 0.5, 0.0};
    ColorMap[DKMAGENTA] = array<float, 3> {0.5, 0.0, 0.5};
    ColorMap[DKCYAN] = array<float, 3> {0.0, 0.5, 0.5};
    ColorMap[DKYELLOW] = array<float, 3> {0.5, 0.5, 0.0};
    ColorMap[DKORANGE] = array<float, 3> {204.0 / 255.0, 102.0 / 255.0, 0.0};
    ColorMap[DKPURPLE] = array<float, 3> {102.0 / 255.0, 0.0, 102.0 / 255.0};
    ColorMap[WHITE] = array<float, 3> { 1.0, 1.0, 1.0};
}

#define ScrToPos(x,y) ((x < 101) ? y/50 * 2 + (x/50) : 23)
#define PosXToScr(x) (x % 2) * 50
#define PosYToScr(y) (y / 2) * 50

/** @fn Screen::click gets called when user clicks in one spot on screen
 **/
void Screen::click(int x, int y, int button)
{
    //if the click was within the palette
    int locationIndex = ScrToPos(x, y);
    if(button == GLUT_LEFT_BUTTON)
    {
        if (locationIndex >= 0 && locationIndex < 16)
            borderColor = colorIndexMap[locationIndex];
        //If click is a shape
        else if(locationIndex > 15 && locationIndex < 22)
            selectedShape = shapeMap[locationIndex];
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex <<
             endl;
        cerr << "selected color = " << borderColor << " selected shape = " <<
             selectedShape << endl;
    }
    else if(button == GLUT_RIGHT_BUTTON)
    {
        if (locationIndex >= 0 && locationIndex < 16)
            fillColor = colorIndexMap[locationIndex];
        else if(locationIndex >= 16 && locationIndex < 22)
            selectedShape = shapeMap[locationIndex];
        //right click on pallete, calculate closest shape center
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex <<
             endl;
        cerr << "fill color = " << fillColor << " selected shape = " << selectedShape <<
             endl;
    }
}

void Screen::clickAndDrag(int x, int y, int lastX, int lastY, int button)
{
    int distanceFromCenter = 0, distanceIndex = 0;
    Shape* temp;
    if(ScrToPos(x, y) > 22 && selectedShape != NONE
            && button == GLUT_LEFT_BUTTON)
    {
        //TODO: replace cout statements with
        switch (selectedShape)
        {
        case LINE:
        {
            shapes.push_back(new Line(x, y, borderColor, lastX, lastY));
            break;
        }
        case ELLIPSE:
        {
            shapes.push_back(new Ellipse((lastX + x) / 2, (lastY + y) / 2 , borderColor,
                                         fillColor, abs(x - lastX) / 2, abs(y - lastY) / 2));
            break;
        }
        case FLDELLIPSE:
        {
            shapes.push_back(new FilledEllipse((lastX + x) / 2, (lastY + y) / 2 ,
                                               borderColor, fillColor, abs(x - lastX) / 2, abs(y - lastY) / 2));
            break;
        }
        case RECTANGLE:
        {
            shapes.push_back(new Rectangle(x, y, borderColor, fillColor, lastX, lastY));
            break;
        }
        case FLDRECTANGLE:
        {
            shapes.push_back(new FilledRectangle(x, y, borderColor, fillColor, lastX,
                                                 lastY));
            break;
        }
        default:
        {
            cout << "Hit default in clickAndDrag" << endl;
            break;
        }
        }
    }
    //right click and drag
    else if(button == GLUT_RIGHT_BUTTON)
    {
        if(x > 100 && !shapes.empty())
        {
            for(unsigned int i = 0; i < shapes.size(); i++)
            {
                if( i == 0 )
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(lastY, lastY);
                else if(shapes.at(i) -> getDistanceFromCenter(lastX,
                        lastY) < distanceFromCenter)
                {
                    distanceIndex = i;
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(lastX, lastY);
                }
            }
            if(distanceFromCenter <= 30000)
            {
                shapes.at(distanceIndex) -> move(x, y);
                temp = shapes.at(distanceIndex);
                shapes.erase(shapes.begin() + distanceIndex);
                shapes.push_back(temp);
            }
        }
    }
    glutPostRedisplay();
    temp = nullptr;
}



void Screen::initPalette()
{
    // Statically draw the palette on the left
    for(int i = 0 ; i < 16 ; i++)
        DrawFilledRectangle(PosXToScr(i), PosYToScr(i), PosXToScr(i) + 50,
                            PosYToScr(i) + 50, ColorMap[colorIndexMap[i]]);
    DrawRectangle(0, 450, 50, 400, array<float, 3> { 1.0, 1.0, 1.0});
    DrawFilledRectangle(51, 450, 100, 400, array<float, 3> { 1.0, 1.0, 1.0});
    DrawEllipse(25, 25, 25, 475, array<float, 3> { 1.0, 1.0, 1.0});
    DrawFilledEllipse(25, 25, 75, 475, array<float, 3> { 1.0, 1.0, 1.0});
    DrawLine(0, 550, 50, 500, array<float, 3> { 1.0, 1.0, 1.0});
}

void Screen::drawShapes()
{
    for(std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
        (*it)->draw();
}


void Screen::keyboardAction(unsigned char key, int x, int y)
{
    int distanceFromCenter = 0, distanceIndex = 0;
    switch ( key )
    {
    // Escape quits program
    case 'q':
    case EscapeKey:
        exit( 0 );
        break;
    case 'd':
    {
        if(x > 100 && !shapes.empty())
        {
            for(unsigned int i = 0; i < shapes.size(); i++)
            {
                if( i == 0 )
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(x, y);
                else if(shapes.at(i) -> getDistanceFromCenter(x, y) < distanceFromCenter)
                {
                    distanceIndex = i;
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(x, y);
                }
            }
            if(distanceFromCenter < 30000)
                shapes.erase(shapes.begin() + distanceIndex);
        }
        break;
    }
    // anything else redraws window
    default:
        glutPostRedisplay();
        break;
    }
}
