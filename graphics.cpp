/*************************************************************************//**
* @file
*****************************************************************************/
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

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws a straight line to the screen using two passed in endpoints.
 *
 * @param[in] x1 - x location of first endpoint
 * @param[in] y1 - y location of first endpoint
 * @param[in] x2 - x location of second endpoint
 * @param[in] y2 - y location of second endpoint
 * @param[in] color - color of the line
 *****************************************************************************/
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


/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws a rectangle using two opposite points as reference
 *
 * @param[in] x1 - x location of first endpoint
 * @param[in] y1 - y location of first endpoint
 * @param[in] x2 - x location of second endpoint
 * @param[in] y2 - y location of second endpoint
 * @param[in] color - color of the rectangle
 *****************************************************************************/
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

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws a filled rectangle using two opposite points as reference
 *
 * @param[in] x1 - x location of first endpoint
 * @param[in] y1 - y location of first endpoint
 * @param[in] x2 - x location of second endpoint
 * @param[in] y2 - y location of second endpoint
 * @param[in] color - color of the inside of rectangle
 *****************************************************************************/
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

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws an ellipse using a center point and and x and y radius
 *
 * @param[in] xRadius - x radius of ellipse
 * @param[in] yRadius - y radius of ellipse
 * @param[in] x - x location of center
 * @param[in] y - y location of center
 * @param[in] color - color of the ellipse
 *****************************************************************************/
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

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws a filled ellipse using a center point and and x and y radius
 *
 * @param[in] xRadius - x radius of ellipse
 * @param[in] yRadius - y radius of ellipse
 * @param[in] x - x location of center
 * @param[in] y - y location of center
 * @param[in] color - color of the inside of the ellipse
 *****************************************************************************/
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



/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * Draws a string specified by user onto the screen
 *
 * @param[in] string - what to write on the screen
 * @param[in] x - x location string
 * @param[in] y - y location of string
 * @param[in] color - color of the letters
 *****************************************************************************/
void DrawTextString( char* string, int x, int y, const array<float, 3> color )
{
    float c[3];
    std::copy(color.begin(), color.end(), c);
    glColor3fv( c );
    glRasterPos2i( x, y );
    while ( *string )
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string++ );
}

