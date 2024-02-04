#include <stdio.h>
#include "../include/Heap.h"

int main()
{

    Heap heap;

    HeapInit(&heap);

    Insert(&heap, 'B');
    Insert(&heap, 'A');
    Insert(&heap, 'D');
    Insert(&heap, 'C');

    for (int i = 1; i <= heap.numOfData; i++)
    {

        printf("%c ", heap.arr[i]);
    }
    printf("\n\n");
    Delete(&heap);
    for (int i = 1; i <= heap.numOfData; i++)
    {

        printf("%c ", heap.arr[i]);
    }
    printf("\n\n");
    Delete(&heap);
    for (int i = 1; i <= heap.numOfData; i++)
    {

        printf("%c ", heap.arr[i]);
    }
    printf("\n\n");
    Delete(&heap);
    for (int i = 1; i <= heap.numOfData; i++)
    {

        printf("%c ", heap.arr[i]);
    }
}