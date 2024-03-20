#ifndef PAGES_H
#define PAGES_H

#include "GUI/Routing/Router.h"
#include "GUI/Widgets/Base/WidgetWithChildren.h"
#include "GUI/Widgets/Container/Column.h"
#include "GUI/Widgets/Container/Row.h"
#include "GUI/Widgets/Content/Text.h"
#include "ProjectUI/Widgets/Header.h"

class HomePage : public WidgetWithChildren {
   public:
    HomePage();
};

class PIDPage : public WidgetWithChildren {
   public:
    PIDPage();
};

class SensorsPage : public WidgetWithChildren {
   public:
    SensorsPage();
};

class SequencesPage : public WidgetWithChildren {
   public:
    SequencesPage();
};

void initializeRoutes();

#endif  // PAGES_H
