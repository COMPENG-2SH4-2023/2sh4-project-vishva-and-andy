#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"
#include "stdlib.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar() != 0)
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
   input = this_input;
}

void GameMechs::clearInput()
{
   input = 0;
}

void GameMechs::generateFood(objPos blockOff)
{
    
    foodPos.x = rand() % (13) + 1;
    foodPos.y = rand() % (28) + 1;  
    foodPos.symbol = 'O';
    if((blockOff.x == foodPos.x) && (blockOff.y == foodPos.y))
    {
        while((blockOff.x == foodPos.x) && (blockOff.y == foodPos.y))
        {
            foodPos.x = rand() % (13) + 1;
            foodPos.y = rand() % (28) + 1;  //blockOff = playerPos
        }
    }
    
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol); 
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score;
}


