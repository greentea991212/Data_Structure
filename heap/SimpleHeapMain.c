#include <stdio.h>
#include <stdlib.h>
#include "../include/SimpleHeap.h"

int main(void)
{

    Heap *heap = (Heap *)malloc(sizeof(Heap));
    HeapInint(heap);

    Insert(heap, 'A', 1);
    Insert(heap, 'B', 2);
    Insert(heap, 'C', 3);
    printf("%c\n", Delete(heap));

    Insert(heap, 'A', 1);
    Insert(heap, 'B', 2);
    Insert(heap, 'C', 3);
    printf("%c\n", Delete(heap));

    while (!IsEmpty(heap))
    {

        printf("%c\n", Delete(heap));
    }

    return 0;
}