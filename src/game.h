#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
    public: 
        Game();
        Block getRandomBlock();
        std::vector<Block> getAllBlocks();
        void draw();
        Grid grid;
        bool gameOver;
        void handleInput();
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        void lockBlock();
        void rotate();
        void Reset();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        bool blockFits();
        Block nextBlock;
        bool isBlockOutside();
};