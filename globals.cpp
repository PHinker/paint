/*************************************************************************//**
* @file
*****************************************************************************/
/*
                    ***** globals.h *****

OpenGL graphics program, based on example code provided by Dr. Weiss for
CSC 300 - Data Structures

Author: Jake and Paul
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/
// guard against multiple inclusions
#ifndef _Globals_H_
#define _Globals_H_
#include "globals.h"

// symbolic constants

// global vars
/** \brief width of window */
int ScreenWidth  = 900;
/** \brief height of window */
int ScreenHeight = 900;
/** \brief map connecting colors to enums */
map<SelectedColor, array<float, 3>> ColorMap;

#endif
