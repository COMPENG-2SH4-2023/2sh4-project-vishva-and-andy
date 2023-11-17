#include "Player.h"


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
}

