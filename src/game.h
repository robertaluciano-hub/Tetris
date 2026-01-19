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
        void handleInput();
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        void lockBlock();
        void rotate();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool isBlockOutside();
};