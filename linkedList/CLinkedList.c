#include <stdio.h>
#include <stdlib.h>
#include "../include/CLinkedList.h"

void ListInit(CList *list)
{

    list->tail = NULL;
    list->curr = NULL;
    list->prev = NULL;
    list->NumOfData = 0;
}

void ListInsertTail(CList *plist, Data pdata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;
    newNode->next = NULL;

    if (plist->tail == NULL)
    {

        plist->tail = newNode;
        newNode->next = plist->tail;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->NumOfData)++;
}

void ListInsertFront(CList *plist, Data pdata)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;
    newNode->next = NULL;

    if (plist->tail == NULL)
    {

        plist->tail = newNode;
        newNode->next = plist->tail;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->NumOfData)++;
}

int LFirst(CList *plist, Data *pdata)
{

    if (plist->tail == NULL)
    {

        printf("데이터가 존재하지 않습니다.");
        return FALSE;
    }
    else
    {

        plist->prev = plist->tail;
        plist->curr = plist->tail->next;
        *pdata = plist->curr->data;

        return TRUE;
    }
}

int LNext(CList *plist, Data *pdata)
{

    if (plist->tail == NULL)
    {

        printf("데이터가 존재하지 않습니다.");
        return FALSE;
    }
    else
    {

        plist->prev = plist->curr;
        plist->curr = plist->curr->next;
        *pdata = plist->curr->data;

        return TRUE;
    }
}

int LCount(CList *plist)
{

    return (plist->NumOfData);
}

Data LRemove(CList *plist)
{

    Node *delNode = plist->curr;
    Data delData = delNode->data;

    if (plist->tail == delNode)
    {

        if (plist->tail == plist->tail->next)
        {

            plist->tail = NULL;
        }
        else
            plist->tail = plist->prev;
    }

    plist->prev->next = plist->curr->next;
    plist->curr = plist->prev;
    free(delNode);

    (plist->NumOfData)--;
    return delData;
}
