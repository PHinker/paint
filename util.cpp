#include <iostream>
#include "util.h"
#include "graphics.h"
#include "globals.h"
#include "rectangle.h"
#include "screen.h"

using namespace std;

void utilityCentral(Event event)
{
   static Screen screen;

   switch (event.event)
   {
      case DISPLAY:
         cout << "Displayed utility central\n";
         screen.initPalette();
         break;
      case KEYBOARD:
         cout << "Keyboard utility central (" << event.key << ", " << event.x << ", " << event.y << ")\n";
         break;
      case MOUSECLICK:
         cout << "Mouse utility central (" << event.key << ", " << event.button << ", " << event.state << ", " << event.x << ", " << event.y << ")\n";
         screen.click(event.x, event.y);
         break;
      case MOUSEDRAG:
         cout << "Mouse utility central (" << event.key << ", " << event.button << ", " << event.state << ", " << event.x << ", " << event.y << ")\n";
         screen.clickAndDrag(event.x, event.y, event.lastX, event.lastY);
         break;
      default:
         cout << "Why am I here?\n";
   }
}
