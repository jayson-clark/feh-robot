#include <FEHLCD.h>

#include "GUI/Widgets/Content/Text.h"

int main() {
    WidgetProperties propExample = {
        .x = 30,
        .y = 30,
        .width = 200,
        .height = 100,
        .foregroundColor = Color(255, 0, 0),
        .borderWidth = 1,
        .borderColor = Color(0, 255, 0),
        .onPress =
            [](Widget *self, InputEvent e) {
                LCD.WriteLine("Pressed.");
            },
        .onRelease =
            [](Widget *self, InputEvent e) {
                LCD.WriteLine("Released.");
            },
        .onEnter =
            [](Widget *self, InputEvent e) {
                self->properties.foregroundColor = GREEN;
                self->hasUpdate = true;
            },
        .onLeave =
            [](Widget *self, InputEvent e) {
                self->properties.foregroundColor = RED;
                self->hasUpdate = true;
            },
    };

    Text *txt = new Text("Hello World!", propExample);

    LCD.Clear();
    txt->draw();

    while (true) {
        float x, y;
        bool pressed = LCD.Touch(&x, &y);
        InputEvent event =
            InputProcessor::getInstance()->processInput(x, y, pressed);

        txt->handleInput(event);

        if (txt->hasUpdate) {
            txt->update(DeltaTime::fromMilliseconds(10)); // Dummy DeltaTime
            txt->layout();

            txt->draw();

#ifdef SIMULATOR
            LCD.Update();
#endif
        }
    }
}
