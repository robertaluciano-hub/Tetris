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
        bool isCellEmpty(int row, int column);
        int clearFullRows();
    private:
        bool isRowFull(int row);
        void clearRow(int row);
        void moveRowDown(int row, int numRows);
        int numCols;
        int numRows;
        int cellSize;
        std::vector<Color> colors;
};