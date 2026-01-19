#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
    public: 
        Game();
        int score;
        void draw();
        bool gameOver;
        void handleInput();
        void moveBlockDown();
        void lockBlock();
        void rotate();
        void Reset();

    private:
        std::vector<Block> blocks;
        Grid grid;
        Block currentBlock;
        Block nextBlock;
        bool blockFits();
        bool isBlockOutside();
        void updateScore(int linesCleared, int moveDownPoints);
        void moveBlockLeft();
        void moveBlockRight();
        Block getRandomBlock();
        std::vector<Block> getAllBlocks();
};