#include "ProjectUI/Widgets/Header.h"

HeaderWidget::HeaderWidget(const std::string &title, Text *actionBtn)
    : Row({}, {}) {
    Text *backBtn = new Text(
        "<",
        WidgetProperties{
            .borderWidth = 1,
            .onPress =
                [](Widget *, InputEvent) {
                    Router::getInstance().redirect("/");
                },
        });

    Text *titleText = new Text(title, {.borderWidth = 1});

    // Adjust width of title widget to the full screen
    titleText->properties.width = 320 - backBtn->properties.width;

    children.push_back(backBtn);
    children.push_back(titleText);
    if (actionBtn) {
        children.push_back(actionBtn);

        // Require a border of 1 pixel
        actionBtn->properties.borderWidth = 1;

        // Adjust the title page to leave room for the action button
        titleText->properties.width -= actionBtn->properties.width;
    }
}
