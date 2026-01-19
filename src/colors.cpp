#include "colors.h"

const Color darkGrey = {26, 31, 40, 255};
const Color green = {102, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color orange = {255, 128, 0, 255};
const Color yellow = {255, 255, 0};
const Color purple = {102, 0, 102, 255};
const Color cyan = {0, 255, 255, 255};
const Color blue = {0, 0, 255, 255};

std::vector<Color> getCellColors() {
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}