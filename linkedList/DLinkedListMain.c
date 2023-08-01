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