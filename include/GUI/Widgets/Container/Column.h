#ifndef COLUMN_H
#define COLUMN_H

#include "GUI/Widgets/Base/WidgetWithChildren.h"

class Column : public WidgetWithChildren
{
public:
    using WidgetWithChildren::WidgetWithChildren;

    void layout() override;
};

#endif // COLUMN_H