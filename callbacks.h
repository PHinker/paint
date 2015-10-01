/*************************************************************************//**
* @file
*****************************************************************************/

#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

/*
                    ***** callbacks.h *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

*/

// OpenGL callback function prototypes

// guard against multiple inclusions
#ifndef _Callbacks_H_
#define _Callbacks_H_
//called when new things need to be drawn to screen
void display( void );
//called when the window is resized
void reshape( int w, int h );
//called when user presses a key
void keyboard( unsigned char key, int x, int y );
//called when user clicks
void mouseclick( int button, int state, int x, int y );

#endif


#endif // CALLBACKS_H_INCLUDED
