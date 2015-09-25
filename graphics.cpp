/*
                    ***** graphics.cpp *****

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
#include "graphics.h"

/******************************************************************************/
/*                          useful graphics routines                          */
/******************************************************************************/

// draw a line using the given RGB color value
void DrawLine( float x1, float y1, float x2, float y2,
               const array<float, 3> color )
{
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glBegin( GL_LINES );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}

/******************************************************************************/

// draw a rectangle using the given RGB color value
void DrawRectangle( float x1, float y1, float x2, float y2,
                    const array<float, 3> color )
{
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glBegin( GL_LINE_LOOP );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/******************************************************************************/

// draw a filled rectangle using the given RGB color value
void DrawFilledRectangle( float x1, float y1, float x2, float y2,
                          const array<float, 3> color )
{
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glBegin( GL_POLYGON );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/******************************************************************************/

// draw an ellipse of given radii at a specified position using the given RGB color value
void DrawEllipse( float xRadius, float yRadius, int x, int y,
                  const array<float, 3> color )
{
    float radius = xRadius < yRadius ? xRadius :
                   yRadius;	// stretch circle into ellipse
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius,
              1.0 );	// by ratio of major to minor axes
    GLUquadricObj* disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/******************************************************************************/

// draw an ellipse of given radii at a specified position using the given RGB color value
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y,
                        const array<float, 3> color)
{
    float radius = xRadius < yRadius ? xRadius :
                   yRadius;	// stretch circle into ellipse
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );
    glScalef( xRadius / radius, yRadius / radius,
              1.0 );	// by ratio of major to minor axes
    GLUquadricObj* disk = gluNewQuadric();
    gluDisk( disk, 0, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/******************************************************************************/

// write a text string at a specified position using the given RGB color value
void DrawTextString( char* string, int x, int y, const array<float, 3> color )
{
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glRasterPos2i( x, y );
    while ( *string )
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string++ );
}

