#include <stdio.h>
#include <stdlib.h>
#include "../include/NDBLinkedList.h"

// Not use DummyNode

void ListInit(List *plist)
{

    plist->head = NULL;
    plist->curr = NULL;
    plist->NumOfData = 0;
}

void ListInsert(List *plist, Data pdata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;
    newNode->left = NULL;

    newNode->right = plist->head;
    if (plist->head != NULL)
    {
        plist->head->left = newNode;
    }

    plist->head = newNode;
    (plist->NumOfData)++;
}

int LFirst(List *plist, Data *pdata)
{

    if (plist->head == NULL)
    {

        printf("데이터가 존재하지 않습니다.\n");
        return FALSE;
    }

    plist->curr = plist->head;
    *pdata = plist->curr->data;

    return TRUE;
}

int LNext(List *plist, Data *pdata)
{

    if (plist->curr->right == NULL)
    {

        printf("데이터가 존재하지 않습니다.\n");
        return FALSE;
    }

    plist->curr = plist->curr->right;
    *pdata = plist->curr;

    return TRUE;
}

int LPrev(List *plist, Data *pdata)
{

    if (plist->curr->left == NULL)
    {

        printf("데이터가 존재하지 않습니다.\n");
        return FALSE;
    }

    plist->curr = plist->curr->left;
    *pdata = plist->curr->data;

    return TRUE;
}

int LCount(List *plist)
{

    return plist->NumOfData;
}
