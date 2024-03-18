#ifndef TEXT_H
#define TEXT_H

#include "GUI/Widgets/Base/Widget.h"

#include "FEHLCD.h"

#include <string.h>

#define CHAR_WIDTH 12
#define CHAR_HEIGHT 17

class Text : public Widget
{
public:
    Text(std::string text, WidgetProperties prop = WidgetProperties{});

    void draw() const override;
};

#endif // TEXT_H