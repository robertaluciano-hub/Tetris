#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
}

Block Game::getRandomBlock() {
    if (blocks.empty()) {
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    // ci assicuriamo che tutti i blocchi escano almeno una volta prima di ripetersi
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::getAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0) {
        gameOver = false;
        Reset();
    }
    switch(keyPressed) {
        case KEY_LEFT:
            moveBlockLeft();
            break;

        case KEY_RIGHT:
            moveBlockRight();
            break;

        case KEY_DOWN:
            moveBlockDown();
            break;
        
        case KEY_UP:
            rotate();
            break;
    }
}

void Game::moveBlockLeft() {
    if(!gameOver) {
        currentBlock.move(0, -1);
        if(isBlockOutside() || !blockFits()) {
            currentBlock.move(0, 1);
        }
    }    
}

void Game::moveBlockRight() {
    if(!gameOver) {
        currentBlock.move(0, 1);
        if(isBlockOutside() || !blockFits()) {
            currentBlock.move(0, -1);
        }
    }
}

void Game::moveBlockDown() {
    if(!gameOver) {
        currentBlock.move(1, 0);
        if(isBlockOutside() || !blockFits()) {
            currentBlock.move(-1, 0);
            lockBlock();
        }
    }
}

void Game::lockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(!blockFits()) {
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    grid.clearFullRows();
}

void Game::rotate() {
    currentBlock.rotate();
    if(isBlockOutside() || !blockFits()) {
        currentBlock.undoRotation();
    }
}

void Game::Reset()
{
    grid.initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

bool Game::blockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();

    for(Position item : tiles) {
        if(!grid.isCellEmpty(item.row, item.column)) {
            return false;
        }
    }
    return true;
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles) {
        if (grid.isCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}
