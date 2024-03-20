#include "ProjectUI/Pages.h"

HomePage::HomePage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    Text* pidBtn = new Text(
        "PID",
        WidgetProperties{
            .width = 160,
            .height = 120,
            .borderWidth = 1,
            .onPress =
                [](Widget*, InputEvent) {
                    Router::getInstance().redirect("/pid");
                },
        });

    Text* sensorsBtn = new Text(
        "Sensors",
        WidgetProperties{
            .width = 160,
            .height = 120,
            .borderWidth = 1,
            .onPress =
                [](Widget*, InputEvent) {
                    Router::getInstance().redirect("/sensors");
                },
        });

    Text* sequencesBtn = new Text(
        "Sequences",
        WidgetProperties{
            .width = 160,
            .height = 120,
            .borderWidth = 1,
            .onPress =
                [](Widget*, InputEvent) {
                    Router::getInstance().redirect("/sequences");
                },
        });

    col->children.push_back(new Row({pidBtn, sensorsBtn}));
    col->children.push_back(new Row({sequencesBtn}));
    col->layout();

    children.push_back(col);
}

PIDPage::PIDPage() : WidgetWithChildren({}, {}) {
    HeaderWidget* header = new HeaderWidget("PID");
    children.push_back(header);
}

SensorsPage::SensorsPage() : WidgetWithChildren({}, {}) {
    HeaderWidget* header = new HeaderWidget("Sensors");
    children.push_back(header);
}

SequencesPage::SequencesPage() : WidgetWithChildren({}, {}) {
    HeaderWidget* header = new HeaderWidget("Sequences", new Text("Go"));
    children.push_back(header);
}

void initializeRoutes() {
    Router& router = Router::getInstance();

    // Create pages
    HomePage* homePage = new HomePage();
    PIDPage* pidPage = new PIDPage();
    SensorsPage* sensorsPage = new SensorsPage();
    SequencesPage* sequencesPage = new SequencesPage();

    // Add routes to the router
    router.addRoute("/", new Route(homePage));
    router.addRoute("/pid", new Route(pidPage));
    router.addRoute("/sensors", new Route(sensorsPage));
    router.addRoute("/sequences", new Route(sequencesPage));

    // Set default route
    router.setDefaultRoute(router.getRoute("/"));
}
