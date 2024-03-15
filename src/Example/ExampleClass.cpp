#include "Example/ExampleCLass.h"

void ExampleClass::mainLoop()
{
    LCD.Clear();
    LCD.WriteLine("Hello, world!");

    while (true)
    {
#ifdef SIMULATOR
        // This code only runs when built for the simulator
        LCD.Update();
#endif
    }
}