#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

enum EventType
{
   DISPLAY,
   KEYBOARD,
   MOUSECLICK,
   MOUSEDRAG,
};

struct Event
{
   EventType event;
   unsigned char key;
   int button, state;
   int x, y, lastX, lastY;
   Event() :
      event(DISPLAY){}
   Event(unsigned char k, int xPos, int yPos) :
      event(KEYBOARD), key(k), x(xPos), y(yPos){}
   Event(int b, int s, int xPos, int yPos) :
      event(MOUSECLICK), button(b), state(s), x(xPos), y(yPos){}
   Event(int b, int xStart, int yStart, int xEnd, int yEnd) :
      event(MOUSEDRAG), button(b), x(xStart), y(yStart), lastX(xEnd), lastY(yEnd){}
};

void initPalette();
void utilityCentral(Event event);
#endif // UTIL_H_INCLUDED
