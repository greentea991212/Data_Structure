#ifndef __HEAP_
#define __HEAP_

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 10

typedef struct _element
{
    // int priority;
    char data;

} Element;

typedef struct _heap
{
    Element arr[HEAP_LEN];
    int numOfData;

} Heap;

void HeapInit(Heap *heap);
int IsEmpty(Heap *heap);
int IsFull(Heap *heap);
int GetParentIndex(int idx);
int GetLeftChildIndex(int idx);
int GetRightChildIndex(int idx);
int GetPriorityChild(Heap *heap, int parentIdx);
void Insert(Heap *heap, char data);
Element Delete(Heap *heap);
void ShowAllElement(Heap *heap);

#endif