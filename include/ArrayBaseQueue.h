#ifndef __AB_QUEUE_
#define __AB_QUEUE_

#define TRUE 1
#define FALSE 0

#define Q_SIZE 5

typedef int DataType;

typedef struct __arrayQueue
{
    DataType arr[Q_SIZE];
    int front;
    int rare;

} Queue;

void QInit(Queue *p);
void Enqueue(Queue *p, DataType data);
void Dequeue(Queue *p);
int IsEmpty(Queue *p);
int IsFull(Queue *p);
int QSize(Queue *p);
DataType QPeek(Queue *p);

#endif
