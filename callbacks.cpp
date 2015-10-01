/*************************************************************************//**
* @file
*****************************************************************************/
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

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * This function redraws the screen when there are new things to be added or
 * updated.
 *****************************************************************************/
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );
    //when there is something to display, call event handler
    utilityCentral(Event());
    // flush graphical output
    glFlush();
}

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * OpenGL callback function that handles the resizing of the window. This gets
 * called at the beginning of the program as well as whenever the user drags a
 * window corner
 *
 * @param[in] w - new width of screen
 * @param[in] h - new height of screen
 *****************************************************************************/
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


/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * OpenGL callback function that handles keyboard clicks. When the user presses
 * a key, it records the key they pressed and the x and y coordinates where they
 * pressed it
 *
 * @param[in] key - key the user pressed
 * @param[in] x - mouse x location when they pressed the key
 * @param[in] y - mouse y location when they pressed the key
 *****************************************************************************/
void keyboard( unsigned char key, int x, int y )
{
    // correct for upside-down screen coordinates
    y = ScreenHeight - y;
    cerr << "keypress: " << key << " (" << int( key ) << ") at (" << x << "," << y
         << ")\n";
    //passes keyboard information to utilitieCentral for processing
    utilityCentral(Event(key, x, y));
}


/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * OpenGL callback function that handles mouse clicks on screen. When the user
 * clicks, OpenGL sends that information to this function, which passes it along
 * to our utility central for processing.
 *
 * @param[in] button - mouse button user pressed
 * @param[in] state - whether button was up or down
 * @param[in] x - mouse x location
 * @param[in] y - mouse y location
 *****************************************************************************/
 void mouseclick( int button, int state, int x, int y )
{
    //records when user presses mouse button down
    static int lastX, LastY;
    y = ScreenHeight - y;
    if(state == GLUT_DOWN)
    {
        lastX = x;
        LastY = y;
    }
    //if they lifed the mouse buton up
    //determine whether it was a click or drag
    //and pass relevant information to utility central
    else if(state == GLUT_UP)
    {
        if(abs(lastX - x) > 25 || abs(LastY - y) > 25)
        {
            utilityCentral(Event(button, x, y, lastX, LastY));
        }
        else
        {
            utilityCentral(Event(button, state, x, y));
        }
    }
}
