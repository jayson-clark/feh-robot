#include "ProjectUI/Pages.h"

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
