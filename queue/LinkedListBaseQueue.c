#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListBaseQueue.h"

// Not use Dummy Node

void QueueInit(Queue *Lqueue)
{

    Lqueue->front = NULL;
    Lqueue->rear = NULL;
    Lqueue->NumOfData = 0;
}

int IsEmpty(Queue *Lqueue)
{

    if (Lqueue->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue *Lqueue, Data data)
{

    Node *newNode = (Node *)malloc((sizeof(Node)));
    newNode->data = data;
    newNode->next = NULL;

    if (IsEmpty(Lqueue))
    {

        Lqueue->front = newNode;
        Lqueue->rear = newNode;
    }
    else
    {

        Lqueue->rear->next = newNode;
        Lqueue->rear = newNode;
    }

    (Lqueue->NumOfData)++;
}

void Dequeue(Queue *Lqueue)
{

    if (IsEmpty(Lqueue))
        return;

    Node *delNode = Lqueue->front;
    Lqueue->front = Lqueue->front->next;
    free(delNode);
    (Lqueue->NumOfData--);
}

Data Peek(Queue *Lqueue)
{

    return Lqueue->front->data;
}