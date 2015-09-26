/*************************************************************************//**
* @file
*****************************************************************************/




#include "screen.h"
/** \brief Macros to translate screen coordinates into
location on palette */

#define ScrToPos(x,y) ((x < 101) ? y/50 * 2 + (x/50) : 23)
/** \brief Translates x coordinate */
#define PosXToScr(x) (x % 2) * 50
/** \brief translates y coordinate */
#define PosYToScr(y) (y / 2) * 50

using namespace std;

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Constructor for screen. Initializes color arrays and adds them to the color map
 * so that we can use enums as array indicies.
 *****************************************************************************/
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



/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * This function is called whenever the user clicks anywhere on the screen.
 * It accepts the coordinates where the user clicked, and translates that
 * to an integer representing a location either in the palette or on the canvas.
 * If the user left clicks a color, it sets their selected border color to it, a right
 * click sets the fill color. If the user clicks on the canvas portion, it does nothing
 * since a click and drag is what draws and moves shapes.
 *
 * @param[in] x - X-coordinate of where the user clicked
 * @param[in] y - Y-coordinate of where the user clicked
 * @param[in] button - Integer representing which mouse button user clicked
 *****************************************************************************/
void Screen::click(int x, int y, int button)
{
    //translate click coordinates to index in palette
    int locationIndex = ScrToPos(x, y);

    //if they left clicked
    if(button == GLUT_LEFT_BUTTON)
    {
        //if the click was a color on the palette, set bordercolor
        if (locationIndex >= 0 && locationIndex < 16)
            borderColor = colorIndexMap[locationIndex];
        //If click is a shape on the palette, set selected shape
        else if(locationIndex > 15 && locationIndex < 22)
            selectedShape = shapeMap[locationIndex];
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex <<
             endl;
        cerr << "selected color = " << borderColor << " selected shape = " <<
             selectedShape << endl;
    }
    //if they right clicked
    else if(button == GLUT_RIGHT_BUTTON)
    {
        //if they right clicked a color, set it to fill color
        if (locationIndex >= 0 && locationIndex < 16)
            fillColor = colorIndexMap[locationIndex];
        //otherwise select shape, same as left click
        else if(locationIndex >= 16 && locationIndex < 22)
            selectedShape = shapeMap[locationIndex];
        cerr << "x: " << x << "  y: " << y << " locationIndex: " << locationIndex <<
             endl;
        cerr << "fill color = " << fillColor << " selected shape = " << selectedShape <<
             endl;
    }
}
/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * This function is called when the user clicks down and then clicks up in a
 * different location, meaning they dragges their mouse somewhere. If they had a shape
 * and color and left clicked, it means they want to draw a shape, so the function adds
 * the chosen shape and its colors to the shape vector, which is then drawn to the screen.
 * If they right clicked near the center of a shape it means they want to move it somewhere else,
 * so it sets the new center of the object to where they released the right mouse button.
 *
 * @param[in] x - X-coordinate of where the user released mouse
 * @param[in] y - Y-coordinate of where the user released mouse
 * @param[in] lastX - Y-coordinate of where the user first clicked
 * @param[in] lastY - Y-coordinate of where the user first clicked
 * @param[in] button - Integer representing which mouse button user clicked
 *****************************************************************************/
void Screen::clickAndDrag(int x, int y, int lastX, int lastY, int button)
{
    //initialize variables to be used in center calculations
    int distanceFromCenter = 0, distanceIndex = 0;
    //temp shape to hold moved shape
    Shape* temp;
    //If the user clicked and dragged on the canvas and not the palette
    if(ScrToPos(x, y) > 22 && selectedShape != NONE
                           && button == GLUT_LEFT_BUTTON)
    {
        //create shape based on shape selection by user and add to vector for drawing
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
        //if they did not drag shape onto canvas and there is a shape to drag
        if(x > 100 && !shapes.empty())
        {   //iterate through shapes vector searching for closest shape to users initial
            //right click
            for(unsigned int i = 0; i < shapes.size(); i++)
            {

                if( i == 0 )
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(lastX, lastY);
                //if the current shapes distance is less then previous min, set smallest index to current shape
                else if(shapes.at(i) -> getDistanceFromCenter(lastX,
                        lastY) < distanceFromCenter)
                {
                    distanceIndex = i;
                    distanceFromCenter = shapes.at(i) -> getDistanceFromCenter(lastX, lastY);
                }
            }
            //once we have the closest shape, if it was close enough to the middle move it to new location
            if(distanceFromCenter <= 30000)
            {
                //swap algorithm, puts shape at back of vector, meaning it will be drawn last and on top of all others
                shapes.at(distanceIndex) -> move(x, y);
                temp = shapes.at(distanceIndex);
                shapes.erase(shapes.begin() + distanceIndex);
                shapes.push_back(temp);
            }
        }
    }
    //redraw the screen and reset temp shape pointer
    glutPostRedisplay();
    temp = nullptr;
}


/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws palette on the left side of the screen when the user starts the program.
 * The palette is used for selecting fill color, border color, and shape type
 *****************************************************************************/
void Screen::initPalette()
{
    //loops through map of colors drawing 50 x 50 squares for the user to click on
    for(int i = 0 ; i < 16 ; i++)
        DrawFilledRectangle(PosXToScr(i), PosYToScr(i), PosXToScr(i) + 50,
                            PosYToScr(i) + 50, ColorMap[colorIndexMap[i]]);
    //draws shapes in 50 x 50 boxes for the user to select
    DrawRectangle(0, 450, 50, 400, array<float, 3> { 1.0, 1.0, 1.0});
    DrawFilledRectangle(51, 450, 100, 400, array<float, 3> { 1.0, 1.0, 1.0});
    DrawEllipse(25, 25, 25, 475, array<float, 3> { 1.0, 1.0, 1.0});
    DrawFilledEllipse(25, 25, 75, 475, array<float, 3> { 1.0, 1.0, 1.0});
    DrawLine(0, 550, 50, 500, array<float, 3> { 1.0, 1.0, 1.0});
}

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Called whenever any shapes are added, modified, or removed. Loops through
 * vector of shapes drawing them to the screen. The shape at spot two of the
 * vector will be drawn on top of all the ones before it, so on and so forth.
 *****************************************************************************/
void Screen::drawShapes()
{
    //uses beautiful iterators to loop through vector drawing shapes to screen
    for(std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++)
        (*it)->draw();
}

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * This function gets called when the user presses a key on the keyboad.
 * If they press 'q' or 'esc' it quits the program, 'd' deletes the shape they
 * are hovering over with their mouse, 'c' clears
 * the canvas of all shapes and all other keys redraws the screen
 *
 * @param[in] key - key the user pressed on the keyboard
 * @param[in] x - X-coordinate of mouse where user pressed key
 * @param[in] y - Y-coordinate of mouse where user pressed key
 *****************************************************************************/
void Screen::keyboardAction(unsigned char key, int x, int y)
{
    //initialize variables used in distance from center loop
    int distanceFromCenter = 0, distanceIndex = 0;
    //switch handling the different key presses
    switch ( key )
    {
    // Escape and q quits program
    case 'q':
    case EscapeKey:
        exit( 0 );
        break;
        //d deletes the shape the pointer is hovering over
    case 'd':
        {
            //iterate through vector of shapes looking for closest center
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
                //when we find the closest center to the mouse, if it is within range
                //remove it from the vector
                if(distanceFromCenter < 30000)
                    shapes.erase(shapes.begin() + distanceIndex);
            }
            break;
        }
        //c removes all shapes from the vector
        case 'c':
            shapes.erase(shapes.begin(), shapes.end());
            break;
    // anything else redraws window
    default:
        glutPostRedisplay();
        break;
    }
}
