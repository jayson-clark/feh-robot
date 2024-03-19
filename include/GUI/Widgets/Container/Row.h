#ifndef ROW_H
#define ROW_H

#include "GUI/Widgets/Base/WidgetWithChildren.h"

class Row : public WidgetWithChildren
{
public:
    using WidgetWithChildren::WidgetWithChildren;

    void layout() override;
};

#endif // ROW_H