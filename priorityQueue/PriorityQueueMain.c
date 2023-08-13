#include <stdio.h>
#include <stdlib.h>
#include "../include/PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{

    PriorityQueue *q = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    PQueueInint(q, DataPriorityComp);

    Enqueue(q, 'A');
    Enqueue(q, 'B');
    Enqueue(q, 'C');

    printf("%c\n", Dequeue(q));

    Enqueue(q, 'A');
    Enqueue(q, 'B');
    Enqueue(q, 'C');

    printf("%c\n", Dequeue(q));

    while (!isEmptyPriorityQueue(q))
    {

        printf("%c\n", Dequeue(q));
    }

    return 0;
}
