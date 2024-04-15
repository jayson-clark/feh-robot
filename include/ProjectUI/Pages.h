#ifndef PAGES_H
#define PAGES_H

#include "GUI/Routing/Router.h"
#include "GUI/Widgets/Base/WidgetWithChildren.h"
#include "GUI/Widgets/Container/Column.h"
#include "GUI/Widgets/Container/Row.h"
#include "GUI/Widgets/Content/Text.h"
#include "ProjectUI/Widgets/Header.h"
#include "ProjectUI/Widgets/Stepper.h"
#include "Robot/Robot.h"

class HomePage : public WidgetWithChildren {
   public:
    HomePage();
};

class PIDPage : public WidgetWithChildren {
   public:
    PIDPage();

   private:
    float Kp = dKp;
    float Ki = dKi;
    float Kd = dKd;

    int sample_rate = dSAMPLE_RATE;
    int inches = 12;
};

class TurnPage : public WidgetWithChildren {
   public:
    TurnPage();

   private:
    int counts = 34;
    int reps = 6;
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
