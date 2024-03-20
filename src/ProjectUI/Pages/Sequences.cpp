#include "ProjectUI/Pages.h"

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
