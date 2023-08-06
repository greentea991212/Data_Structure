#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListBaseQueue.h"

int main(void)
{

    Queue *q = (Queue *)malloc(sizeof(Queue));
    QueueInit(q);

    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);
    Enqueue(q, 6);
    Enqueue(q, 7);
    Enqueue(q, 8);

    while (!IsEmpty(q))
    {

        printf("%d ", Peek(q));
        Dequeue(q);
    }

    return 0;
}