/*
                    ***** callbacks.cpp *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// include files
#include <cstdlib>
#include <iostream>
using namespace std;

// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>
#include "globals.h"
#include "callbacks.h"
#include "graphics.h"
#include "util.h"
#include "screen.h"

/******************************************************************************/
/*                          OpenGL callback functions                         */
/******************************************************************************/

// callback function that tells OpenGL how to redraw window
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    utilityCentral(DISPLAY, '.', 0, 0, 0, 0);

    // flush graphical output
    glFlush();
}

/******************************************************************************/

// callback function that tells OpenGL how to resize window
// note that this is called when the window is first created
void reshape( int w, int h )
{
    if (w < SCREEN_WIDTH_MIN || h < SCREEN_HEIGHT_MIN)
    {
        glutReshapeWindow(SCREEN_WIDTH_MIN, SCREEN_HEIGHT_MIN);
    }
    // store new window dimensions globally
    ScreenWidth = w;
    ScreenHeight = h;

    // how to project 3-D scene onto 2-D
    glMatrixMode( GL_PROJECTION );		// use an orthographic projection
    glLoadIdentity();				// initialize transformation matrix
    gluOrtho2D( 0.0, w, 0.0, h );		// make OpenGL coordinates
    glViewport( 0, 0, w, h );			// the same as the screen coordinates
}

/******************************************************************************/

// callback function that tells OpenGL how to handle keystrokes
void keyboard( unsigned char key, int x, int y )
{
    // correct for upside-down screen coordinates
    y = ScreenHeight - y;
    cerr << "keypress: " << key << " (" << int( key ) << ") at (" << x << "," << y << ")\n";

    utilityCentral(KEYBOARD, key, 0, 0, x, y);
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

/******************************************************************************/

// callback function for mouse button click events
void mouseclick( int button, int state, int x, int y )
{
    static int lastX, LastY;

    y = ScreenHeight - y;

    utilityCentral(MOUSE, '.', button, state, x, y);
    switch ( button )
    {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN){
            lastX = x;
            LastY = y;

        } else if(state == GLUT_UP){
            if(abs(lastX - x) > 25 || abs(LastY - y) > 25){
                cerr << "Left click and drag" << endl;
            } else {
                cerr << "Left click in place" << endl;
            }
        }
    }
}
