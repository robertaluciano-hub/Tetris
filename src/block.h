#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block 
{
    public:
        Block();
        void draw(int offsetX, int offsetY);
        void move(int rows, int column);
        void rotate();
        std::vector<Position> getCellPositions();
        int id;
        void undoRotation();
        std::map<int, std::vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int columnOffset;
        std::vector<Color> colors;
        
};