#include "GUI/Widgets/Base/Widget.h"

bool isEventInsideWidget(const Widget &widget, const InputEvent &event) {
    // Access the widget's properties
    const auto &prop = widget.properties;

    // Check if the event's coordinates are within the widget's bounding box
    bool isInsideX = event.x >= prop.x && event.x <= (prop.x + prop.width);
    bool isInsideY = event.y >= prop.y && event.y <= (prop.y + prop.height);

    return isInsideX && isInsideY;
}

void Widget::draw() const {
    //
    // BUGGIN
    //

    // Draw background
    LCD.SetFontColor(properties.backgroundColor.toInt());
    LCD.FillRectangle(properties.x, properties.y, properties.width,
                      properties.height);

    // Draw border
    LCD.SetFontColor(properties.borderColor.toInt());
    for (int i = 0; i < properties.borderWidth; i++) {
        LCD.DrawRectangle(properties.x + i, properties.y + i,
                          properties.width - 2 * i, properties.height - 2 * i);
    }
}

void Widget::update(DeltaTime dt) { hasUpdate = false; }

void Widget::handleInput(InputEvent event) {
    // Check if the event was inside the widget bounding box
    bool isInside = isEventInsideWidget(*this, event);

    // Create a dummy previous event for enter and leave callbacks
    InputEvent prevEvent;
    prevEvent.x = event.x + event.dx;
    prevEvent.y = event.y + event.dy;

    // If a MOUSEDOWN event and inside call the onPress callback
    if (event.type == MOUSEDOWN && isInside) properties.onPress(this, event);

    // If a MOUSEUP event and inside call the onRelease and onLeave callbacks
    else if (event.type == MOUSEUP && isInside) {
        properties.onRelease(this, event);
        properties.onLeave(this, event);
    }
    // The conditions for the following two blocks are backward and idk why

    // If inside and prevEvent not inside call the onEnter callback
    else if (!isInside && isEventInsideWidget(*this, prevEvent))
        properties.onEnter(this, event);

    // If not inside and prevEvent inside call the onLeave callback
    else if (isInside && !isEventInsideWidget(*this, prevEvent))
        properties.onLeave(this, event);
}
