#include "GUI/Widgets/Base/WidgetWithChild.h"

WidgetWithChild::WidgetWithChild(Widget *child, WidgetProperties prop)
    : Widget(prop), child(child) {
    if (child) child->properties.parent = this;
}

WidgetWithChild::~WidgetWithChild() { delete child; }

void WidgetWithChild::layout() {
    if (!child) return;

    child->properties.x = properties.x;
    child->properties.y = properties.y;

    child->layout();
}

void WidgetWithChild::draw() const {
    Widget::draw();

    if (child) child->draw();
}

void WidgetWithChild::update(DeltaTime dt) {
    Widget::update(dt);

    if (child) child->update(dt);
}

void WidgetWithChild::handleInput(InputEvent event) {
    Widget::handleInput(event);

    if (child) child->handleInput(event);
}
