#include "GUI/Widgets/Container/Column.h"

void Column::layout()
{
    int currentY = properties.y + properties.padding; // Start from the top padding
    int maxWidth = -1;

    for (auto &child : children)
    {
        child->properties.x = properties.x + properties.padding; // Include left padding
        child->properties.y = currentY;
        currentY += child->properties.height; // Move down by child's height

        child->layout(); // Layout the child

        int childWidthWithPadding = child->properties.width + 2 * properties.padding;
        if (childWidthWithPadding > maxWidth)
            maxWidth = childWidthWithPadding;
    }

    // Adjust the column height
    properties.height = currentY - properties.y + properties.padding; // Include bottom padding
    properties.width = maxWidth; // Column width based on the widest child and padding
}
