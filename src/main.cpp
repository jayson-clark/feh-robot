#include <FEHLCD.h>

#include "GUI/Widgets/Base/WidgetWithChild.h"
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

    WidgetProperties propExample1 = {
        .x = 100,
        .y = 150,
    };

    Text *txt = new Text("Hello World!", propExample);
    WidgetWithChild *ex = new WidgetWithChild(new Text("Widget with child"), propExample1);

    LCD.Clear();
    txt->layout();
    ex->layout();

    txt->draw();
    ex->draw();

    while (true) {
        float x, y;
        bool pressed = LCD.Touch(&x, &y);
        InputEvent event =
            InputProcessor::getInstance()->processInput(x, y, pressed);

        txt->handleInput(event);
        ex->handleInput(event);

        if (txt->hasUpdate) {
            txt->update(DeltaTime::fromMilliseconds(10));  // Dummy DeltaTime
            txt->layout();

            ex->update(DeltaTime::fromMilliseconds(10)); // Dummy DeltaTime
            ex->layout();

            txt->draw();
            ex->draw();

#ifdef SIMULATOR
            LCD.Update();
#endif
        }
    }
}
