#include <stdio.h>
#include <stdlib.h>
#include "../include/DLinkedList.h"

int WhoIsPreceed(int num1, int num2)
{

    if (num1 < num2)
        return 0;
    else
        return 1;
}

int main(void)
{

    List *list = (List *)malloc(sizeof(List));
    DATA data;

    ListInit(list);

    SetSortRule(list, WhoIsPreceed);

    ListInsert(list, 12);
    ListInsert(list, 11);
    ListInsert(list, 15);
    ListInsert(list, 22);
    ListInsert(list, 13);
    ListInsert(list, 14);
    ListInsert(list, 21);
    ListInsert(list, 20);

    printf("���� ����Ǿ��� �������� �� : %d\n", LCount(list));
    printf("���� ����Ǿ��� ��� ������ : ");

    if (!LFirst(list, &data))
    {

        printf("����Ʈ�� �����Ͱ� �������� �ʽ��ϴ�.\n");
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