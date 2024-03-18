#include "GUI/Widgets/Base/WidgetWithChildren.h"

WidgetWithChildren::WidgetWithChildren(std::vector<Widget *> children,
                                       WidgetProperties prop)
    : Widget(prop), children(children) {
    for (auto &child : children)
        if (child) child->properties.parent = this;
}

WidgetWithChildren::~WidgetWithChildren() {
    for (auto &child : children) delete child;
}

void WidgetWithChildren::layout() {
    for (auto &child : children) {
        child->properties.x = properties.x;
        child->properties.y = properties.y;

        child->layout();
    }
}

void WidgetWithChildren::draw() const {
    Widget::draw();

    for (auto &child : children)
        if (child) child->draw();
}

void WidgetWithChildren::update(DeltaTime dt) {
    Widget::update(dt);

    for (auto &child : children)
        if (child) child->update(dt);
}

void WidgetWithChildren::handleInput(InputEvent event) {
    Widget::handleInput(event);

    for (auto &child : children)
        if (child) child->handleInput(event);
}
