#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

/*
                    ***** callbacks.h *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// OpenGL callback function prototypes

// guard against multiple inclusions
#ifndef _Callbacks_H_
#define _Callbacks_H_

void display( void );
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y );
void mousedrag( int x, int y );

#endif


#endif // CALLBACKS_H_INCLUDED
