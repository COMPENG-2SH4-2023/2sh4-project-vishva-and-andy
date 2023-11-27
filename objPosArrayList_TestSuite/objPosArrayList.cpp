#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList < ARRAY_MAX_CAP)
    {
        sizeList++;

        for(int i = sizeList; i > 0; i--)
        {
            aList[i] = aList[i-1];
        }

        aList[0] = thisPos;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList < ARRAY_MAX_CAP)
    {
        aList[sizeList++] = thisPos;
    }
}

void objPosArrayList::removeHead()
{
    if(sizeList > 0)
    {
        for(int i = 0; i < sizeList - 1 ; i++)
        {
            aList[i] = aList[i+1];
        }

        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if(sizeList > 0)
    {        
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if(sizeList > 0)
    {        
        returnPos.symbol = aList[0].symbol;
        returnPos.x = aList[0].x;
        returnPos.y = aList[0].y;
    }
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if(sizeList > 0)
    {        
        returnPos.symbol = aList[sizeList-1].symbol;
        returnPos.x = aList[sizeList-1].x;
        returnPos.y = aList[sizeList-1].y;
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(sizeList != 0 && sizeList > 0 && index >= 0 && index < sizeList)
    {        
        returnPos.symbol = aList[index].symbol;
        returnPos.x = aList[index].x;
        returnPos.y = aList[index].y;
    }
}