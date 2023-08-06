#include <stdlib.h>
#include <stdio.h>
#include "../include/DBLinkedList.h"

int main(void)
{

    List *list = (List *)malloc(sizeof(List));
    ListInit(list);
    Data data;

    ListInsert(list, 1);
    ListInsert(list, 2);
    ListInsert(list, 3);
    ListInsert(list, 4);
    ListInsert(list, 5);
    ListInsert(list, 6);
    ListInsert(list, 7);
    ListInsert(list, 8);

    if (LFirst(list, &data))
    {

        printf("%d ", data);

        while (LNext(list, &data))
        {

            printf("%d ", data);
        }
    }

    printf("\n\n");

    if (LFirst(list, &data))
    {

        if (data % 2 == 0)
            LRemove(list);

        while (LNext(list, &data))
        {
            if (data % 2 == 0)
                LRemove(list);
        }
    }

    if (LFirst(list, &data))
    {

        printf("%d ", data);

        while (LNext(list, &data))
        {

            printf("%d ", data);
        }
    }
    return 0;
}