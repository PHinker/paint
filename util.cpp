/*************************************************************************//**
* @file
*****************************************************************************/
#include <iostream>
#include "util.h"
#include "graphics.h"
#include "globals.h"
#include "rectangle.h"
#include "screen.h"

using namespace std;

/**************************************************************************//**
 * @author Paul Hinker, Jake Davidson
 *
 * @par Description:
 * This function gets called when an event happens in callbacks. Depending on the enum
 * and data passed in it will do different things. When a mouse click is passed in,
 * it sends that data to the click function in the container class screen. When
 * a mouse drag is sent in, it sends it to the clickAndDrag function in screen.
 * It does the same for keyboard presses, sending them to keyboardAction in screen.
 *
 * @param[in] event - structure that contains data about the event to handle
 *****************************************************************************/
void utilityCentral(Event event)
{
    //declare screen object
    static Screen screen;
    //switch the enum containing type of event
    //call appropriate function in screen.
    switch (event.event)
    {
    case DISPLAY:
        {
            cout << "Displayed utility central\n";
            screen.initPalette();
            screen.drawShapes();
            break;
        }
    case KEYBOARD:
        cout << "Keyboard utility central (" << event.key << ", " << event.x << ", " <<
             event.y << ")\n";
        screen.keyboardAction(event.key, event.x, event.y);
        break;
    case MOUSECLICK:
        cout << "Mouse utility central (" << event.key << ", " << event.button << ", "
             << event.state << ", " << event.x << ", " << event.y << ")\n";
        screen.click(event.x, event.y, event.button);
        break;
    case MOUSEDRAG:
        cout << "Mouse utility central (" << event.key << ", " << event.button << ", "
             << event.state << ", " << event.x << ", " << event.y << ")\n";
        screen.clickAndDrag(event.x, event.y, event.lastX, event.lastY, event.button);
        break;
    default:
        cout << "Why am I here?\n";
    }
}
