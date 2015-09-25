#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "graphics.h"
#include "util.h"
#include "globals.h"
#include "shape.h"
#include "rectangle.h"
#include "line.h"
#include "ellipse.h"
#include "filledellipse.h"
#include "filledrectangle.h"

class Screen
{
   private:
      vector<Shape*> shapes;
      SelectedColor borderColor;
      SelectedColor fillColor;
      SelectedShape selectedShape;

   public:
      Screen();
      void drawShapes();
      void click(int x, int y, int button);
      void clickAndDrag(int x, int y, int lastX, int lastY);
      void keyboardAction(unsigned char key, int x, int y);
      void initPalette();
};

#endif // SCREEN_H_INCLUDED
