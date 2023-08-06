#include <stdlib.h>
#include <stdio.h>
#include "../include/DBLinkedList.h"

// using Dummy Node

void ListInit(List *plist)
{

    Node *newNodeForHead = (Node *)malloc(sizeof(Node));
    plist->head = newNodeForHead;
    Node *newNodeForTail = (Node *)malloc(sizeof(Node));
    plist->tail = newNodeForTail;

    plist->head->left = NULL;
    plist->head->right = plist->tail;
    plist->tail->left = plist->head;
    plist->tail->right = NULL;

    plist->NumOfData = 0;
}

void ListInsert(List *plist, Data pdata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;

    newNode->left = plist->head;
    newNode->right = plist->head->right;
    plist->head->right->left = newNode;
    plist->head->right = newNode;

    (plist->NumOfData)++;
}

int LFirst(List *plist, Data *pdata)
{

    if (plist->head->right == plist->tail)
        return FALSE;

    plist->curr = plist->head->right;
    *pdata = plist->curr->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{

    if (plist->curr->right == plist->tail)
        return FALSE;

    plist->curr = plist->curr->right;
    *pdata = plist->curr->data;

    return TRUE;
}

int LPrev(List *plist, Data *pdata)
{

    if (plist->curr->left == plist->head)
        return FALSE;

    plist->curr = plist->curr->left;
    *pdata = plist->curr->data;

    return TRUE;
}

Data LRemove(List *plist)
{

    Node *delNode = plist->curr;
    Data delData = plist->curr->data;
    plist->curr->left->right = plist->curr->right;
    plist->curr->right->left = plist->curr->left;

    free(delNode);
    (plist->NumOfData)--;
    return delData;
}

int LCount(List *plist)
{

    return plist->NumOfData;
}