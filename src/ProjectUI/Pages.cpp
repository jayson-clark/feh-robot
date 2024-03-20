#include "ProjectUI/Pages.h"

HomePage::HomePage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    auto btnProp = [](std::string path) -> WidgetProperties {
        return {
            .width = 160,
            .height = 120,
            .borderWidth = 1,
            .onPress =
                [path](Widget*, InputEvent) {
                    Router::getInstance().redirect(path);
                },
        };
    };

    Text* pidBtn = new Text("PID", btnProp("/pid"));
    Text* sensorsBtn = new Text("Sensors", btnProp("/sensors"));
    Text* sequencesBtn = new Text("Sequences", btnProp("/sequences"));

    col->children = {new Row({pidBtn, sensorsBtn}), new Row({sequencesBtn})};
    col->layout();

    children = {col};
}

PIDPage::PIDPage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    // Dummy Go button
    Text* goBtn = new Text("Go");

    HeaderWidget* header = new HeaderWidget("PID", goBtn);

    StepperWidget* pStepper = new StepperWidget(&Kp, 0, 5, 0.1);
    StepperWidget* iStepper = new StepperWidget(&Ki, 0, 5, 0.1);
    StepperWidget* dStepper = new StepperWidget(&Kd, 0, 5, 0.1);
    StepperWidget* inchesStepper = new StepperWidget(&inches, 0, 36, 1);

    col->children = {
        header,
        new Row({new Text("P: "), pStepper}),
        new Row({new Text("I: "), iStepper}),
        new Row({new Text("D: "), dStepper}),
        new Row({new Text("inches: "), inchesStepper}),
    };
    col->layout();

    children = {col};
}

SensorsPage::SensorsPage() : WidgetWithChildren({}, {}) {
    HeaderWidget* header = new HeaderWidget("Sensors");
    children.push_back(header);
}

SequencesPage::SequencesPage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    // Dummy segment selecters
    StepperWidget* checkpointSelector =
        new StepperWidget({"checkpoint1", "checkpoint2", "checkpoint3"});
    StepperWidget* segmentSelector = new StepperWidget({"(a)", "(b)", "(c)"});

    // Dummy Go button that prints out currently selected segment/checkpoint
    Text* goBtn = new Text(
        "Go",
        WidgetProperties{
            .onPress =
                [checkpointSelector, segmentSelector](Widget*, InputEvent) {
                    std::cout << checkpointSelector->getValue() << " - "
                              << segmentSelector->getValue() << std::endl;
                },
        });

    HeaderWidget* header = new HeaderWidget("Sequences", goBtn);

    col->children = {header, checkpointSelector, segmentSelector};
    col->layout();

    children.push_back(col);
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
