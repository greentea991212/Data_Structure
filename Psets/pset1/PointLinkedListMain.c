#include <stdio.h>
#include <stdlib.h>
#include "PointLinkedList.h"

int WhatIsProceed(Point *pos1, Point *pos2)
{
    if (pos1->xpos != pos2->xpos)
    {
        if (pos1->xpos < pos2->xpos)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        if (pos1->ypos < pos2->ypos)
            return TRUE;
        else
            return FALSE;
    }
}

int main()
{

    List *list = (List *)malloc(sizeof(List));
    ListInit(list);

    Point *point;
    
    SetSortRule(list, WhatIsProceed);

    point = PointInit();
    setPoint(point, 1, 2);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 1, 3);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 3, 2);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 4, 2);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 7, 2);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 2, 5);
    ListInsert(list, point);

    point = PointInit();
    setPoint(point, 3, 2);
    ListInsert(list, point);

    LSearch(list);
}