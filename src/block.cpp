#include "block.h"

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
    colors = getCellColors();
}

void Block::draw() {
    std::vector<Position> tiles = getCellPositions();
    for(Position item: tiles) {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int rows, int column) {
    rowOffset += rows;
    columnOffset += column;
}

void Block::rotate()
{
    rotationState++;

    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

std::vector<Position> Block::getCellPositions() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

void Block::undoRotation()
{
    rotationState--;
    if(rotationState == -1) {
        rotationState = cells.size() - 1;
    }
}
