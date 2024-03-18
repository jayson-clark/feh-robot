#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

struct Color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    Color() : red(0), green(0), blue(0) {} // Default constructor: black
    Color(uint8_t r, uint8_t g, uint8_t b) // Constructor with RGB values
        : red(r), green(g), blue(b)
    {
    }

    // Convert the color to a 32-bit integer for FEHLCD lib
    uint32_t toInt() const
    {
        return (static_cast<uint32_t>(red) << 16) |
               (static_cast<uint32_t>(green) << 8) |
               static_cast<uint32_t>(blue);
    }

    // Constructor with a 32-bit color value
    Color(uint32_t color)
        : red((color >> 16) & 0xFF),  // Extract the red component
          green((color >> 8) & 0xFF), // Extract the green component
          blue(color & 0xFF)          // Extract the blue component
    {
    }
};

#endif // COLOR_H