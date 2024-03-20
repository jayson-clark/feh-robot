#ifndef HEADER_H
#define HEADER_H

#include "GUI/Routing/Router.h"
#include "GUI/Widgets/Container/Row.h"
#include "GUI/Widgets/Content/Text.h"

class HeaderWidget : public Row {
   public:
    HeaderWidget(const std::string &title, Text *actionBtn = nullptr);
};

#endif  // HEADER_H
