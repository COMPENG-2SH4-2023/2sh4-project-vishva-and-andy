#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic     

    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case ' ':
            break;
        case 'W':
        case 'w':
            if(myDir == DOWN)
            {
                myDir != UP;
            }
            else
            {
                myDir = UP;
               
            }
            break;
        case 'S':
        case 's':
            if(myDir == UP)
            {
                myDir != DOWN;
            }
            else
            {
                myDir = DOWN;
            }
            break;
        case 'A':
        case 'a':
            if(myDir == RIGHT)
            {
                myDir != LEFT;
            }
            else
            {
                myDir = LEFT;
            }
            break;
        case 'D':
        case 'd':
            if(myDir == LEFT)
            {
                myDir != RIGHT;
            }
            else
            {
                myDir = RIGHT;
            }
            break; 

        default:
            break;
    }   
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myDir)
    {
        case UP:
            playerPos.x -= 1;
            MacUILib_init();
            MacUILib_clearScreen();
            break;

        case LEFT:
            playerPos.y -= 1;
            MacUILib_init();
            MacUILib_clearScreen();
            break;

        case DOWN:
            playerPos.x += 1;
            MacUILib_init();
            MacUILib_clearScreen();
            break;
        
        case RIGHT:
            playerPos.y += 1;
            MacUILib_init();
            MacUILib_clearScreen();
            break;
        default:
            break;
    }
}

