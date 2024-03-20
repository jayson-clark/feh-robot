#include "GUI/Widgets/Container/Row.h"

void Row::layout() {
    int currentX = properties.x + properties.padding; // Start from the left padding
    int maxHeight = -1;

    for (auto &child : children) {
        
        child->properties.x = currentX;
        child->properties.y = properties.y + properties.padding; // Include top padding
        currentX += child->properties.width; // Move right by child's width

        child->layout(); // Layout the child

        int childHeightWithPadding = child->properties.height + 2 * properties.padding;
        if (childHeightWithPadding > maxHeight)
            maxHeight = childHeightWithPadding;
    }

    // Adjust the row width
    properties.width = currentX - properties.x + properties.padding; // Include right padding
    properties.height = maxHeight; // Row height based on the tallest child and padding
}
