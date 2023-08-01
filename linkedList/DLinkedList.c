#include <stdio.h>
#include <stdlib.h>
#include "../include/DLinkedList.h"

void ListInit(List *plist)
{

    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->curr = NULL;
    plist->prev = NULL;

    plist->numOfData = 0;
    plist->comp = NULL;
}

void ListInsert(List *plist, DATA Ldata)
{
    if (plist->comp == NULL)
    {
        FInsert(plist, Ldata);
    }
    else
        SInsert(plist, Ldata);
}

void FInsert(List *plist, DATA Ldata)
{

    Node *newNode = (Node *)malloc(sizeof(newNode));
    newNode->data = Ldata;
    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, DATA *Ldata)
{

    if (plist->head->next == NULL)
        return FALSE;
    else
    {

        plist->prev = plist->head;
        plist->curr = plist->prev->next;
        *Ldata = plist->curr->data;

        return TRUE;
    }
}

int LNext(List *plist, DATA *Ldata)
{

    if (plist->curr->next == NULL)
        return FALSE;
    else
    {

        plist->prev = plist->curr;
        plist->curr = plist->curr->next;
        *Ldata = plist->curr->data;

        return TRUE;
    }
}

DATA LRemove(List *plist)
{

    Node *delNode = plist->curr;
    DATA r_data = plist->curr->data;

    plist->prev->next = plist->curr->next;
    plist->curr = plist->prev;

    free(delNode);
    (plist->numOfData)--;

    return r_data;
}

int LCount(List *plist)
{

    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(int, int))
{

    plist->comp = comp;
}

void SInsert(List *plist, DATA Ldata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = Ldata;
    newNode->next = NULL;

    (plist->numOfData)++;

    plist->curr = plist->head;

    while (1)
    {

        if (plist->curr->next == NULL)
            break;
        if (plist->comp(newNode->data, plist->curr->next->data) == 0)
            break;

        plist->curr = plist->curr->next;
    }

    newNode->next = plist->curr->next;
    plist->curr->next = newNode;
}