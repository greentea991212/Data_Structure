#include <stdio.h>
#include <stdlib.h>
#include "../include/Deque.h"

void DequeInit(Deque *pdeq)
{

    pdeq->head = (Node *)malloc(sizeof(Node));
    pdeq->tail = (Node *)malloc(sizeof(Node));
    pdeq->head->left = NULL;
    pdeq->head->right = pdeq->tail;
    pdeq->tail->left = pdeq->head;
    pdeq->tail->right = NULL;

    pdeq->numOfData = 0;
}

void addFirst(Deque *pdeq, Data pdata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;

    newNode->right = pdeq->head->right;
    newNode->left = pdeq->head;
    pdeq->head->right->left = newNode;

    pdeq->head->right = newNode;

    (pdeq->numOfData)++;
}

void addLast(Deque *pdeq, Data pdata)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = pdata;

    newNode->right = pdeq->tail;
    newNode->left = pdeq->tail->left;
    pdeq->tail->left->right = newNode;

    pdeq->tail->left = newNode;
    (pdeq->numOfData)++;
}

Data removeFirst(Deque *pdeq)
{

    Node *delNode = pdeq->head->right;
    pdeq->head->right->right->left = pdeq->head;
    pdeq->head->right = pdeq->head->right->right;

    free(delNode);
    delNode = NULL;
    (pdeq->numOfData)--;
}
Data removeLast(Deque *pdeq)
{

    Node *delNode = pdeq->tail->left;
    pdeq->tail->left->left->right = pdeq->tail;
    pdeq->tail->left = pdeq->tail->left->left;

    free(delNode);
    delNode = NULL;
    (pdeq->numOfData)--;
}
Data peekFirst(Deque *pdeq)
{

    return pdeq->head->right->data;
}
Data peekLast(Deque *pdeq)
{

    return pdeq->tail->left->data;
}

int isEmpty(Deque *pdeq)
{

    if (pdeq->head->right == pdeq->tail)
        return TRUE;
    return FALSE;
}