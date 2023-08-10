#include <stdio.h>
#include <stdlib.h>
#include "../include/Deque.h"

int main(void)
{

    Deque *deq = (Deque *)malloc(sizeof(Deque));
    DequeInit(deq);

    addFirst(deq, 3);
    addFirst(deq, 2);
    addFirst(deq, 1);

    addLast(deq, 4);
    addLast(deq, 5);
    addLast(deq, 6);

    while (!(isEmpty(deq)))
    {

        printf("%d ", peekFirst(deq));
        removeFirst(deq);
    }

    printf("\n");

    addFirst(deq, 3);
    addFirst(deq, 2);
    addFirst(deq, 1);
    addLast(deq, 4);
    addLast(deq, 5);
    addLast(deq, 6);

    while (!(isEmpty(deq)))
    {

        printf("%d ", peekLast(deq));
        removeLast(deq);
    }

    return 0;
}