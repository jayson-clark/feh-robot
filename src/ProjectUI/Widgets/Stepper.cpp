#include "ProjectUI/Widgets/Stepper.h"

StepperWidget::StepperWidget(std::vector<std::string> strings) : Row({}, {}) {
    if (strings.empty()) return;  // Require at least one string

    int* index = new int(0);
    Text* valueText = new Text(strings[*index]);

    Text* leftArrow = new Text("<");
    leftArrow->properties.onPress = [this, valueText, index, strings](
                                        Widget*, InputEvent) mutable {
        // Decremement index and wrap to end if necessary
        if (--(*index) < 0) *index = strings.size() - 1;

        valueText->properties.textContent = strings[*index];
        Router::getInstance().hasUpdate = true;
    };

    Text* rightArrow = new Text(">");
    rightArrow->properties.onPress = [this, valueText, index, strings](
                                         Widget*, InputEvent) mutable {
        // Incremement index and wrap to beginning if necessary
        if (++(*index) >= strings.size()) *index = 0;

        valueText->properties.textContent = strings[*index];
        Router::getInstance().hasUpdate = true;
    };

    children = {leftArrow, valueText, rightArrow};
}

StepperWidget::StepperWidget(int* value, int min, int max, int increment)
    : Row({}, {}) {
    if (!value) return;

    Text* valueText = new Text(std::to_string(*value));

    Text* leftArrow = new Text("<");
    leftArrow->properties.onPress = [value, min, increment, valueText](
                                        Widget*, InputEvent) mutable {
        *value -= increment;
        if (*value < min) *value = min;

        valueText->properties.textContent = std::to_string(*value);
        Router::getInstance().hasUpdate = true;
    };

    Text* rightArrow = new Text(">");
    rightArrow->properties.onPress = [value, max, increment, valueText](
                                         Widget*, InputEvent) mutable {
        *value += increment;
        if (*value > max) *value = max;

        valueText->properties.textContent = std::to_string(*value);
        Router::getInstance().hasUpdate = true;
    };

    children = {leftArrow, valueText, rightArrow};
}

StepperWidget::StepperWidget(
    float* value, float min, float max, float increment)
    : Row({}, {}) {
    if (!value) return;

    Text* valueText = new Text(std::to_string(*value));

    Text* leftArrow = new Text("<");
    leftArrow->properties.onPress = [value, min, increment, valueText](
                                        Widget*, InputEvent) mutable {
        *value -= increment;
        if (*value < min) *value = min;

        valueText->properties.textContent = std::to_string(*value);
        Router::getInstance().hasUpdate = true;
    };

    Text* rightArrow = new Text(">");
    rightArrow->properties.onPress = [value, max, increment, valueText](
                                         Widget*, InputEvent) mutable {
        *value += increment;
        if (*value > max) *value = max;

        valueText->properties.textContent = std::to_string(*value);
        Router::getInstance().hasUpdate = true;
    };

    children = {leftArrow, valueText, rightArrow};
}

std::string StepperWidget::getValue() {
    return children[1]->properties.textContent;
}
