#include "ProjectUI/Pages.h"
#include "Robot/Robot.h"

using namespace Robot;

PIDPage::PIDPage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    StepperWidget* pStepper = new StepperWidget(&Kp, 0, 5, 0.02);
    StepperWidget* iStepper = new StepperWidget(&Ki, 0, 5, 0.02);
    StepperWidget* dStepper = new StepperWidget(&Kd, 0, 5, 0.02);
    StepperWidget* sampleStepper = new StepperWidget(&sample_rate, 25, 300, 5);
    StepperWidget* inchesStepper = new StepperWidget(&inches, 0, 36, 1);

    Text* goBtn = new Text("Go");
    goBtn->properties.onPress = [this](Widget*, InputEvent) {
        Robot::driveRamp(inches, 6.5, Kp, Ki, Kd, sample_rate);
    };

    HeaderWidget* header = new HeaderWidget("PID", goBtn);

    col->children = {
        header,
        new Row({new Text("P: "), pStepper}),
        new Row({new Text("I: "), iStepper}),
        new Row({new Text("D: "), dStepper}),
        new Row({new Text("sample: "), sampleStepper}),
        new Row({new Text("inches: "), inchesStepper}),
    };
    col->layout();

    children = {col};
}
