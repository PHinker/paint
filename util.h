/*************************************************************************//**
* @file
*****************************************************************************/
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

/*!
* @brief enum that specifies what type of event to handle
*/
enum EventType
{
    DISPLAY,
    KEYBOARD,
    MOUSECLICK,
    MOUSEDRAG,
};

/*!
* @brief Contains information about the event that is happening
* and constructors that assign enums and data depending on what is
* passed in.
*/
struct Event
{
    /** \brief type of event to handle */
    EventType event;
    /** \brief keyboard key pressed by user */
    unsigned char key;
    /** \brief mouse button pressed */
    int button;
    /** \brief mouse button position (up or down) */
    int state;
    /** \brief x-coordinate of mouseclick */
    int x;
    /** \brief x-coordinate of mouseclick */
    int y;
    /** \brief x-coordinate of initial mouseclick (used for drag) */
    int lastX;
    /** \brief y-coordinate of initial mouseclick (used for drag) */
    int lastY;

    /** \brief if there are no other params, display routine */
    Event() :
        event(DISPLAY) {}
    /** \brief keyboard event */
    Event(unsigned char k, int xPos, int yPos) :
        event(KEYBOARD), key(k), x(xPos), y(yPos) {}
    /** \brief mouse click in place */
    Event(int b, int s, int xPos, int yPos) :
        event(MOUSECLICK), button(b), state(s), x(xPos), y(yPos) {}
    /** \brief mouse drag across screen */
    Event(int b, int xStart, int yStart, int xEnd, int yEnd) :
        event(MOUSEDRAG), button(b), x(xStart), y(yStart), lastX(xEnd), lastY(yEnd) {}
};

void utilityCentral(Event event);
#endif // UTIL_H_INCLUDED
