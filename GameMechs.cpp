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
   //not needed but how to implement?
}

void GameMechs::generateFood(objPos blockOff)
{
    
    blockOff.x = rand() % (13) + 1;
    blockOff.y = rand() % (28) + 1; //transfer to getFoodPos function
    blockOff.symbol = 'O';
    
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(rand() % (13) + 1, rand() % (28) + 1, 'O'); //still working on
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score;
}


