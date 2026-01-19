#pragma once
#include <vector>
#include <raylib.h>

class Grid 
{
    public:
        int grid[20][10]; 
        Grid();
        void initialize();
        void print();
        void draw();
        bool isCellOutside(int row, int column);
    private:
        int numCols;
        int numRows;
        int cellSize;
        std::vector<Color> colors;
};