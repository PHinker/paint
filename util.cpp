#include <iostream>
#include "util.h"
#include "graphics.h"
#include "globals.h"
#include "screen.h"

using namespace std;

void utilityCentral(EventType event, unsigned char key, int button, int state, int x, int y)
{
   static Screen screen;

   switch (event)
   {
      case DISPLAY:
         cout << "Displayed utility central\n";
         screen.initPalette();
         break;
      case KEYBOARD:
         cout << "Keyboard utility central (" << key << ", " << x << ", " << y << ")\n";
         break;
      case MOUSE:
         cout << "Mouse utility central (" << key << ", " << button << ", " << state << ", " << x << ", " << y << ")\n";
         screen.click(x, y);
         break;
      default:
         cout << "Why am I here?\n";
   }
}
