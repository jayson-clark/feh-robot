#ifndef INPUT_H
#define INPUT_H

#include <iostream>

enum InputType
{
    MOUSEDOWN,
    MOUSEUP,
    MOUSEMOVE
};

struct InputEvent
{
    float x = -1, y = -1, dx, dy;
    bool pressed;
    InputType type;
};

class InputProcessor
{
private:
    // Private Static instance pointer
    static InputProcessor *instance;

    // Private constructor to prevent instantiation
    InputProcessor() {}

    // Private copy constructor and assignment operator to prevent copying
    InputProcessor(const InputProcessor &) = delete;
    InputProcessor &operator=(const InputProcessor &) = delete;

    // Previous input event
    InputEvent previousEvent;

public:
    // Public static function to get the instance of the class
    static InputProcessor *getInstance();

    InputEvent processInput(float x, float y, bool pressed);
};

#endif // INPUT_H