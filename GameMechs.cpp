#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

void GameMechs::setLoseFlag()
{
    input = ' ';
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

}

void GameMechs::generateFood(objPos blockOff)
{
    
    blockOff.x = rand() % (13) + 1;
    blockOff.y = rand() % (28) + 1;
    blockOff.symbol = 'O';
    
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}


