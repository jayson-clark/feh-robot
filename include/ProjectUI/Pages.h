#ifndef PAGES_H
#define PAGES_H

#include "GUI/Routing/Router.h"
#include "GUI/Widgets/Base/WidgetWithChildren.h"
#include "GUI/Widgets/Container/Column.h"
#include "GUI/Widgets/Container/Row.h"
#include "GUI/Widgets/Content/Text.h"

class HomePage : public WidgetWithChildren {
   public:
    HomePage(WidgetProperties prop = {});
};

class Page1 : public WidgetWithChildren {
   public:
    Page1(WidgetProperties prop = {});
};

class Page2 : public WidgetWithChildren {
   public:
    Page2(WidgetProperties prop = {});
};

void initializeRoutes();

#endif  // PAGES_H
