#include "ProjectUI/Pages.h"

SequencesPage::SequencesPage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    // Dummy segment selecters
    StepperWidget* checkpointSelector = new StepperWidget({"checkpoint5"});

    std::vector<std::string> keys;

    // Iterate through the map and store the keys
    for (const auto& pair : Robot::checkpoint5) {
        keys.push_back(pair.first);
    }

    StepperWidget* segmentSelector = new StepperWidget(keys);

    // Dummy Go button that prints out currently selected segment/checkpoint
    Text* goBtn = new Text(
        "Go",
        WidgetProperties{
            .onPress =
                [checkpointSelector, segmentSelector](Widget*, InputEvent) {
                    LCD.Clear();
                    LCD.WriteLine("Ready...");
                    Robot::checkpoint5[segmentSelector->getValue()]();
                    Router::getInstance().hasUpdate = true;
                },
        });

    HeaderWidget* header = new HeaderWidget("Sequences", goBtn);

    Text* fullRunBtn2 = new Text(
        "Full Run",
        WidgetProperties{
            .borderWidth = 1,
            .onPress =
                [](Widget*, InputEvent) {
                    LCD.Clear();
                    LCD.WriteLine("Ready...");
                    Robot::processSequence(Robot::checkpoint5);
                    Router::getInstance().hasUpdate = true;
                },
        });

    col->children = {
        header, segmentSelector, new Text(""), new Text(""), fullRunBtn2};
    col->layout();

    children.push_back(col);
}
