#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');

    // more actions to be included

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic     

    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case ' ':
            mainGameMechsRef->setExitTrue();
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

    objPos currentHead;

    playerPosList->getHeadElement(currentHead);

    // PPA3 Finite State Machine logic
    switch (myDir)
    {
        case UP:
            currentHead.x -= 1;

            if(currentHead.x <= 0)
            {
                currentHead.x = mainGameMechsRef -> getBoardSizeX() - 2;
            }
            break;

        case LEFT:
            currentHead.y -= 1;

            if(currentHead.y <= 0)
            {
                currentHead.y = mainGameMechsRef -> getBoardSizeY() - 2;
            }
            break;

        case DOWN:
            currentHead.x += 1;

            if(currentHead.x >= mainGameMechsRef->getBoardSizeX())
            {
                currentHead.x = 1;
            }
            break;
        
        case RIGHT:
            currentHead.y += 1;

            if(currentHead.y >= mainGameMechsRef -> getBoardSizeY())
            {
                currentHead.y = 1;
            }
            
            break;

        case STOP:
        default:
            break;
    }

    playerPosList -> insertHead(currentHead);
    playerPosList -> removeTail();
}
