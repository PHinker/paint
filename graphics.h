/*
                    ***** graphics.h *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// useful graphics function prototypes

// guard against multiple inclusions
#ifndef _Graphics_H_
#define _Graphics_H_
#include <array>
using namespace std;

void initOpenGL( void );
void DrawLine( float x1, float y1, float x2, float y2,
               const array<float, 3> color );
void DrawRectangle( float x1, float y1, float x2, float y2,
                    const array<float, 3> color );
void DrawFilledRectangle( float x1, float y1, float x2, float y2,
                          const array<float, 3> color );
void DrawEllipse( float xRadius, float yRadius, int x, int y,
                  const array<float, 3> color );
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y,
                        const array<float, 3> color );
void DrawTextString( char* string, int x, int y, const array<float, 3> color );

#endif
