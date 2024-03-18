#include "GUI/Utility/Input.h"

InputProcessor *InputProcessor::getInstance()
{
    static InputProcessor instance;
    return &instance;
}

InputEvent InputProcessor::processInput(float x, float y, bool pressed)
{
    InputEvent event;

    event.x = x;
    event.y = y;
    event.pressed = pressed;

    event.dx = 0;
    event.dy = 0;

    if (previousEvent.x == -1 && previousEvent.y == -1)
    {
        event.type = pressed ? MOUSEDOWN : MOUSEUP;
    }
    else
    {
        event.dx = x - previousEvent.x;
        event.dy = y - previousEvent.y;

        if (previousEvent.pressed == event.pressed)
            event.type = MOUSEMOVE;
        else
            event.type = pressed ? MOUSEDOWN : MOUSEUP;
    }

    // Save the current event as previousEvent for future comparison
    previousEvent = event;

    return event;
}