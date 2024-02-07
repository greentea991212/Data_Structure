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

    ShowAllElement(&heap);
    Delete(&heap);
    ShowAllElement(&heap);

    Delete(&heap);
    ShowAllElement(&heap);

    Delete(&heap);
    ShowAllElement(&heap);
    return 0;
}
