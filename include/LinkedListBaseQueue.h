#ifndef __LL_BASE_QUEUE_H__
#define __LL_BASE_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{

    Data data;
    struct _node *next;

} Node;

typedef struct _LinkedListQueue
{
    Node *front;
    Node *rear;
    int NumOfData;

} Queue;

void QueueInit(Queue *Lqueue);
int IsEmpty(Queue *Lqueue);

void Enqueue(Queue *Lqueue, Data data);
void Dequeue(Queue *Lqueue);
Data Peek(Queue *Lqueue);

#endif