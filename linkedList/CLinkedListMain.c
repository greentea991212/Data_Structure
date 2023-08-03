#include <stdio.h>
#include <stdlib.h>
#include "../include/CLinkedList.h"

int main(void)
{

    CList *list = (CList *)malloc(sizeof(CList));
    ListInit(list);

    int data;
    int nodeCount = 0;

    ListInsertTail(list, 3);
    ListInsertTail(list, 4);
    ListInsertTail(list, 5);

    ListInsertFront(list, 2);
    ListInsertFront(list, 1);

    if (LFirst(list, &data))
    {

        printf("%d ", data);

        for (int i = 0; i < LCount(list) * 3 - 1; i++)
        {

            if (LNext(list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    nodeCount = LCount(list);

    if (nodeCount != 0)
    {

        LFirst(list, &data);
        if (data % 2 == 0)
            LRemove(list);

        for (int i = 0; i < LCount(list) - 1; i++)
        {

            LNext(list, &data);
            if (data % 2 == 0)
                LRemove(list);
        }
    }

    if (LFirst(list, &data))
    {

        printf("%d ", data);

        for (int i = 0; i < LCount(list) - 1; i++)
        {
            if (LNext(list, &data))
                printf("%d ", data);
        }
    }

    return 0;
}