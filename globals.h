#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

/*
                    ***** globals.cpp *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/
#include <map>
using namespace std;

// keypresses
const int EscapeKey = 27;

// colors
enum SelectedColor
{
   BLACK, RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, ORANGE, PURPLE,
   DKBLUE, DKRED, DKGREEN, DKMAGENTA, DKCYAN, DKYELLOW, DKORANGE,
   DKPURPLE, WHITE, LASTCOLOR,
};

enum SelectedShape
{
   NONE, LINE, TEXT, RECTANGLE, FLDRECTANGLE, ELLIPSE, FLDELLIPSE,
};

// global vars
extern int ScreenWidth;
extern int ScreenHeight;
extern map<SelectedColor, array<float, 3>> ColorMap;

#define SCREEN_WIDTH_MIN 300
#define SCREEN_HEIGHT_MIN 300

#endif // GLOBALS_H_INCLUDED
