#include "misaligned.h"

std::map<int, std::string> getColorMap() {
    return {
        {0, "Black"}, {1, "Brown"}, {2, "Red"},
        {3, "Orange"}, {4, "Yellow"}, {5, "Green"},
        {6, "Blue"}, {7, "Violet"}, {8, "Grey"}, {9, "White"}
    };
}

std::string getColorForNumber(int num) {
    auto colorMap = getColorMap();
    if (colorMap.find(num) != colorMap.end())
        return colorMap[num];
    return "Invalid";
}
