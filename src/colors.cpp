#include "colors.h"

const Color darkGrey = {26, 31, 40, 255};
const Color green = {102, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color orange = {255, 128, 0, 255};
const Color yellow = {255, 255, 0};
const Color purple = {166, 0, 247, 255};
const Color cyan = {0, 255, 255, 255};
const Color blue = {0, 0, 255, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

std::vector<Color> getCellColors() {
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}