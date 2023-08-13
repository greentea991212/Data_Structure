#include <stdio.h>
#include <stdlib.h>
#include "../include/UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{

    Heap *heap = (Heap *)malloc(sizeof(Heap));
    HeapInit(heap, DataPriorityComp);

    Insert(heap, 'A');
    Insert(heap, 'B');
    Insert(heap, 'C');
    printf("%c\n", Delete(heap));

    Insert(heap, 'A');
    Insert(heap, 'B');
    Insert(heap, 'C');
    printf("%c\n", Delete(heap));

    while (!IsEmpty(heap))
    {
        printf("%c\n", Delete(heap));
    }

    return 0;
}