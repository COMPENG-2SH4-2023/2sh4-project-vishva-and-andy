#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "time.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGm;
Player* myPlayer;
objPos playerPos;
objPos foodPos;

time_t t;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int mat[15][30];

int main(void)
{

    Initialize();

    while(myGm->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    int i,j;
    srand((unsigned) time(&t));
    myGm = new GameMechs(15,30);
    myPlayer = new Player(myGm);


    myGm->generateFood(playerPos);  //may need to fix 
    myGm->getFoodPos(foodPos);
   
}

void GetInput(void)
{
   myGm->getInput();
}

void RunLogic(void)
{
    objPos tempBody;
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    playerBody->getHeadElement(tempBody);
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGm->clearInput();

    if (myPlayer->checkSelfCollision())
    {
        myGm -> setLoseFlag();
        return;
    }

    if((tempBody.x == foodPos.x) && (tempBody.y == foodPos.y))
    {
        playerBody->insertTail(tempBody);   //changed from insert head
        int a;
        for(a=0; a<playerBody->getSize(); a++)
        {
            playerBody->getElement(tempBody, a);
            myGm->generateFood(tempBody);
        }
        myGm->getFoodPos(foodPos);
        myGm->incrementScore();
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    if(myGm->getLoseFlagStatus() == false)
    {
        int i,j;
        
        bool drawn;

        objPos tempBody;
        
        objPosArrayList* playerBody = myPlayer->getPlayerPos();

        for(i=0; i<myGm->getBoardSizeX(); i++)
        {
            printf("\n");
            for(j=0; j<myGm->getBoardSizeY(); j++)
            {
                
                drawn = false;

                for(int k = 0; k < playerBody -> getSize(); k++)
                {
                    playerBody -> getElement(tempBody, k);
                    if((tempBody.x == i) && (tempBody.y == j))
                    {
                        MacUILib_printf("%c", tempBody.symbol);
                        drawn = true;
                        break;
                    }
                }
                
                if(drawn) continue;

                if((foodPos.x == i) && (foodPos.y == j))
                {
                    MacUILib_printf("%c", foodPos.symbol);
                }
                else if((i == 0) || (i == (myGm->getBoardSizeX() - 1)))
                {
                    MacUILib_printf("#");
                }
                else if((j == 0) || (j == (myGm->getBoardSizeY() - 1)))
                {
                    MacUILib_printf("#");
                }
                else 
                {
                    MacUILib_printf(" ");
                }
                MacUILib_printf("%c", mat[i][j]);
                
            }
        }
        MacUILib_printf("\n");
        
        //printf("Board Size: [%d][%d], Player Position: <%d,%d>, Symbol: %c", myGm->getBoardSizeX(), myGm->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
        MacUILib_printf("Score: %d", myGm->getScore());
    }
    else if(myGm->getLoseFlagStatus() == true)
    {
        MacUILib_printf("Snake Died!\n");
        MacUILib_printf("Score: %d\n", myGm->getScore());
        MacUILib_printf("Hit Space Bar to Exit");
    }
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}