#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();

    initialize();
}

void Grid::initialize() {
        for (int row=0; row < numRows; row++) {
            for(int col=0; col < numCols; col++) {
                grid[row][col] = 0;
            }
        }
    }

void Grid::print() {
    for (int row=0; row < numRows; row++) {
            for(int col=0; col < numCols; col++) {
                std::cout << grid[row][col] << " ";
            }
            std::cout << std::endl;
        }
}

void Grid::draw() {
    for(int row=0; row < numRows; row++) {
        for(int col = 0; col < numCols; col++) {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }
    return true;
}
