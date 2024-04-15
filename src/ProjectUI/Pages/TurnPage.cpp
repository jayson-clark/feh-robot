#include "ProjectUI/Pages.h"
#include "Robot/Robot.h"

using namespace Robot;

TurnPage::TurnPage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    StepperWidget* inchesStepper = new StepperWidget(&counts, 0, 250, 2);
    StepperWidget* repsStepper = new StepperWidget(&reps, 1, 9, 1);

    Text* goBtn = new Text("Go");
    goBtn->properties.onPress = [this](Widget*, InputEvent) {
        for (int i = 0; i < reps; i++) {
            Robot::turnCounts(counts);
        }
    };

    Text* quickTestBtn = new Text("Quick Test");
    quickTestBtn->properties.onPress = [this](Widget*, InputEvent) {
        Robot::turnCounts(DEG_15);
        Robot::turnCounts(DEG_15);
        Robot::turnCounts(DEG_30);
        Robot::turnCounts(DEG_30);

        Sleep(500);

        Robot::turnCounts(DEG_45);
        Robot::turnCounts(DEG_45);

        Sleep(500);

        Robot::turnCounts(DEG_90);
    };

    HeaderWidget* header = new HeaderWidget("Turning", goBtn);

    col->children = {
        header,
        new Row({new Text("counts: "), inchesStepper}),
        new Row({new Text("reps: "), repsStepper}),
        new Text(""),
        new Text(""),
        quickTestBtn,
    };
    col->layout();

    children = {col};
}
