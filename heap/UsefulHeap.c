#include <stdio.h>
#include <stdlib.h>
#include "../include/UsefulHeap.h"

void HeapInit(Heap *pheap, int (*setPriorityFunc)(Data, Data))
{

    pheap->numOfData = 0;
    pheap->comp = setPriorityFunc;
}

int IsEmpty(Heap *pheap)
{

    if (pheap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int getPriorityOfChild(Heap *pheap, int idx)
{

    int leftChild = idx * 2;
    int rightChild = idx * 2 + 1;

    if (leftChild > pheap->numOfData)
        return 0;
    else if (leftChild == pheap->numOfData)
        return leftChild;
    else
    {

        if (pheap->comp(pheap->arr[leftChild], pheap->arr[rightChild]) < 0)
            return rightChild;
        else
            return leftChild;
    }
}

void Insert(Heap *pheap, Data data)
{

    int insertIndex = (pheap->numOfData) + 1;
    int parent;

    while (insertIndex != 1)
    {
        parent = insertIndex / 2;
        if (pheap->comp(data, pheap->arr[parent]) > 0)
        {

            pheap->arr[insertIndex] = pheap->arr[parent];
            insertIndex = parent;
        }
        else break;
    }

    pheap->arr[insertIndex] = data;
    pheap->numOfData++;
}

Data Delete(Heap *pheap)
{
    Data delteData = pheap->arr[1];
    Data lastData = pheap->arr[pheap->numOfData];

    int parent = 1;
    int child;

    while ((child = getPriorityOfChild(pheap, parent)) != 0)
    {

        if (pheap->comp(lastData, pheap->arr[child]) > 0)
            break;
        pheap->arr[parent] = pheap->arr[child];
        parent = child;
    }

    pheap->arr[parent] = lastData;
    pheap->numOfData--;

    return delteData;
}
