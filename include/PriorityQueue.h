#ifndef __PRIORITY_QUEUE_H_
#define __PRIORITY_QUEUE_H_

/*Using Heap*/
#include "UsefulHeap.h"

typedef Heap PriorityQueue;
typedef char Data;

void PQueueInint(PriorityQueue *q, int (*setPriorityFunc)(Data, Data));
int isEmptyPriorityQueue(PriorityQueue *q);

void Enqueue(PriorityQueue *q, Data data);
Data Dequeue(PriorityQueue *q);

#endif