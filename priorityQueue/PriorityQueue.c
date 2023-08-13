#include "../include/PriorityQueue.h"
#include "../include/UsefulHeap.h"

void PQueueInint(PriorityQueue *q, int (*setPriorityFunc)(Data, Data))
{

    HeapInit(q, setPriorityFunc);
}
int isEmptyPriorityQueue(PriorityQueue *q)
{

    IsEmpty(q);
}

void Enqueue(PriorityQueue *q, Data data)
{
    Insert(q, data);
}
Data Dequeue(PriorityQueue *q)
{

    return Delete(q);
}