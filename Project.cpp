#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGm;
Player* myPlayer;
objPos playerPos;
objPos foodPos;


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
    myGm = new GameMechs(15,30);
    myPlayer = new Player(myGm);
    myPlayer->getPlayerPos(playerPos);

    myGm->generateFood(foodPos);
    myGm->getFoodPos(foodPos);

    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            if((playerPos.x == i) && (playerPos.y == j))
            {
                mat[i][j] = playerPos.symbol;
            }
            else if((i == 0) || (i == 14))
            {
                mat[i][j] = '#';
            }
            else if((j == 0) || (j == 29))
            {
                mat[i][j] = '#';
            }
            else 
            {
                mat[i][j] = ' ';
            }
        }
    }
    

   
}

void GetInput(void)
{
   myGm->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    int i,j;
    myPlayer->getPlayerPos(playerPos);
    myGm->getFoodPos(foodPos);

    for(i=0; i<15; i++)
    {
        printf("\n");
        for(j=0; j<30; j++)
        {
            if((playerPos.x == i) && (playerPos.y == j))
            {
                mat[i][j] = playerPos.symbol;
            }
            else if((i == 0) || (i == 14))
            {
                mat[i][j] = '#';
            }
            else if((j == 0) || (j == 29))
            {
                mat[i][j] = '#';
            }
            else 
            {
                mat[i][j] = ' ';
            }
            printf("%c", mat[i][j]);
            
        }
    }
    printf("\n");

    if((playerPos.x == 0) || (playerPos.x == 14))  //lose conditions
    {
        myGm->setLoseFlag();
    }
    else if((playerPos.y == 0) || (playerPos.y == 29))
    {
        myGm->setLoseFlag();
    }
    
    printf("Board Size: [%d][%d], Player Position: <%d,%d>, Symbol: %c", myGm->getBoardSizeX(), myGm->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
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
