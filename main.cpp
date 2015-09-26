/*************************************************************************//**
 * @file
 *
 * @mainpage program 1 - Paint
 *
 * @section course_section Course Information
 *
 * @author Paul Hinker, Jake Davidson
 *
 * @date September 25, 2015
 *
 * @par Professor:
 *         Professor Hinker
 *
 * @par Course:
 *         CSC 300 - 10:00am
 *
 * @par Location:
 *         McLaury Building, Room 313
 *
 * @section program_section Program Information
 *
 * @details This program uses OpenGL and GLUT to create a paint program where a user can
 * select shapes and colors to draw to the screen with their mouse. They do this by selecing
 * border colors (left mouse), fill colors(right mouse), and shapes on a palette on the left.
 * Once they have selected their shapes and colors, they can click and drag on the canvas to
 * draw the shape. By right clicking and dragging near the center of a shape they can move it
 * to a new location. Shapes moved this way will be drawn on top of all other shapes.
 * Hovering over a shape and pressing 'd' will delete the nearest shape.
 *
 * There are 16 colors ranging from red to purple. Shapes are rectangle (filled or unfilled),
 * ellipse (filled or unfilled) or line.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      Place .cpp, .h, and makefile in directory. Call make in terminal and
 *      ./main will start program
 *
 * @par Usage:
   @verbatim
   make
   ./main
   @endverbatim
 *
 *****************************************************************************/


// include files
#include <cstdlib>
#include <iostream>
using namespace std;

// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>
#include "screen.h"
#include "callbacks.h"
#include "globals.h"

// function prototypes
void initOpenGL();


/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Start of program. Initializes openGL, then enters main loop of callback
 * functions.
 *
 * @param[in] argc - the number of command line arguments passed by the user
 * @param[in] argv - a 2D character array, each command line argument is one
 *                          line of the array
 *
 * @returns 0 - not required but stops compiler warnings
 *****************************************************************************/
 int main( int argc, char* argv[] )
{
    // perform various OpenGL initializations
    glutInit( &argc, argv );
    initOpenGL();
    // go into OpenGL/GLUT main loop, never to return
    glutMainLoop();
    // yeah I know, but it keeps compilers from bitching
    return 0;
}

/******************************************************************************/

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Creates OpenGL window, names it, and specifies callback functions.
 *****************************************************************************/
void initOpenGL()
{
    glutInitDisplayMode( GLUT_RGBA |
                         GLUT_SINGLE );	// 32-bit graphics and single buffering
    glutInitWindowSize( ScreenWidth, ScreenHeight);// initial window size
    glutInitWindowPosition( 100, 50 );	// initial window  position
    glutCreateWindow( "OpenGL Demo" );	// window title
    glClearColor( 0.0, 0.0, 0.0, 0.0 );	// use black for glClear command
    // callback routines
    glutDisplayFunc( display );	// how to redisplay window
    glutReshapeFunc( reshape );	// how to resize window
    glutKeyboardFunc( keyboard );// how to handle key presses
    glutMouseFunc( mouseclick);	// how to handle mouse events
}
