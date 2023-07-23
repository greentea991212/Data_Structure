#include <stdio.h>
#include "../include/ArrayBaseQueue.h"

void QInit(Queue *p)
{
    p->front = 0;
    p->rare = 0;
}

void Enqueue(Queue *p, DataType data)
{
    if (IsFull(p))
    {

        printf("Q is Full!\n");
        return;
    }

    p->rare = (p->rare + 1) % Q_SIZE;
    p->arr[p->rare] = data;
}

void Dequeue(Queue *p)
{
    if (IsEmpty(p))
    {

        printf("Q is Empty");
        return;
    }
    p->front = (p->front + 1) % Q_SIZE;
    p->arr[p->front] = -1;
}

int IsEmpty(Queue *p)
{

    if (p->front == p->rare)
        return TRUE;
    else
        return FALSE;
}

int IsFull(Queue *p)
{

    if ((p->front) == ((p->rare + 1) % Q_SIZE))
        return TRUE;
    else
        return FALSE;
}

int QSize(Queue *p)
{

    if (p->rare > p->front)
        return (p->rare - p->front);
    else
        return (Q_SIZE + p->rare - p->front);
}

DataType QPeek(Queue *p)
{
    return p->arr[(p->front + 1) % Q_SIZE];
}
