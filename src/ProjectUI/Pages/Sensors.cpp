#include "ProjectUI/Pages.h"

SensorsPage::SensorsPage() : WidgetWithChildren({}, {}) {
    HeaderWidget* header = new HeaderWidget("Sensors");
    children.push_back(header);
}
