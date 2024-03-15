#include <FEHLCD.h>

int main()
{
    LCD.WriteLine("Hello World!");
    while (1)
    {
#ifdef SIMULATOR
        LCD.Update();
#endif
    }
}