#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

enum EventType
{
   DISPLAY,
   KEYBOARD,
   MOUSE,
};

void initPalette();
void utilityCentral(EventType event, unsigned char key, int button, int state, int x, int y);
#endif // UTIL_H_INCLUDED
