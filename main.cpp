/*
                    ***** JandPPaint *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Authors: Jake , Paul Hinker
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
#include "screen.h"
#include "callbacks.h"
#include "globals.h"

// function prototypes
void initOpenGL();

/******************************************************************************/

// main() function
int main( int argc, char *argv[] )
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

// various commands to initialize OpenGL and GLUT
void initOpenGL()
{
    glutInitDisplayMode( GLUT_RGBA | GLUT_SINGLE );	// 32-bit graphics and single buffering

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
