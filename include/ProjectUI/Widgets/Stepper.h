#ifndef STEPPER_H
#define STEPPER_H

#include "GUI/Routing/Router.h"
#include "GUI/Widgets/Container/Row.h"
#include "GUI/Widgets/Content/Text.h"

class StepperWidget : public Row {
   public:
    // Constructors for different types of stepper values
    StepperWidget(std::vector<std::string> strings);
    StepperWidget(int* value, int min, int max, int increment = 1);
    StepperWidget(float* value, float min, float max, float increment = 0.5);

    std::string getValue();
};

#endif  // STEPPER_H
