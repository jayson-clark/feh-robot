#include <FEHLCD.h>

#include "GUI/Routing/Router.h"
#include "ProjectUI/Pages.h"

int main() {
    initializeRoutes();

    while (true) {
        Router &router = Router::getInstance();
        Route *route = router.getCurrentRoute();

        route->update(DeltaTime::fromMilliseconds(10));
        route->layout();
        route->draw();

        router.hasUpdate = false;

#ifdef SIMULATOR
        LCD.Update();
#endif

        while (!router.hasUpdate) {
            float x, y;
            bool pressed = LCD.Touch(&x, &y);
            InputEvent event =
                InputProcessor::getInstance()->processInput(x, y, pressed);

            route->handleInput(event);
        }
    }
}
