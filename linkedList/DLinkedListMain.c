#include <stdio.h>
#include <stdlib.h>
#include "../include/DLinkedList.h"

int main(void)
{

    List *list = (List *)malloc(sizeof(List));
    DATA data;

    ListInit(list);

    ListInsert(list, 11);
    ListInsert(list, 12);
    ListInsert(list, 13);
    ListInsert(list, 14);
    ListInsert(list, 15);
    ListInsert(list, 20);
    ListInsert(list, 21);
    ListInsert(list, 22);

    printf("현재 저장되어진 데이터의 수 : %d\n", LCount(list));
    printf("현재 저장되어진 모든 데이터 : ");

    if (!LFirst(list, &data))
    {

        printf("리스트에 데이터가 존재하지 않습니다.\n");
    }
    else
    {

        printf("%d ", data);
        while (LNext(list, &data))
        {

            printf("%d ", data);
        }
    }

    printf("\n");
}