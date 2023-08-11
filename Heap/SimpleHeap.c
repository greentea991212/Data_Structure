#include <stdio.h>
#include <stdlib.h>
#include "../include/SimpleHeap.h"

void HeapInint(Heap *pheap)
{

    pheap->numOfData = 0;
}

int IsEmpty(Heap *pheap)
{

    if (pheap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int getParentIndex(int idx)
{

    return idx / 2;
}

int getLeftChildIndex(int idx)
{

    return idx * 2;
}

int getRightChildIndex(int idx)
{

    return idx * 2 + 1;
}

int getPriorityOfChild(Heap *pheap, int idx)
{

    /*
        Priority Queue의 규칙으로 인해, 새로운 노드의 추가시 왼쪽 자식 위치에 추가 되는
        규칙을 통해서 왼쪽 자식노드가 자리 잡아지는 Index값을 기준으로 삼는다.
    */

    // 1. 인자로 전달받은 노드에 대해 자식 노드가 존재하지 않는 경우
    if (getLeftChildIndex(idx) > pheap->numOfData)
    {

        return FALSE;
    }
    // 2. 인자로 전달받은 노드에 대한 자식 노드가 1개만 존재하는 경우
    // 인자로 전달받은 노드의 자식노드 Index값이 현재 저장되어진 데이터의 수가 같다는 것은
    // 제일 마지막 노드임을 의미한다. 때문에 이는 인자로 전달 받은 노드의 자식노드가 하나라는 것이다.
    else if (getLeftChildIndex(idx) == pheap->numOfData)
    {

        return getLeftChildIndex(idx);
    }
    // 3. 인자로 전달받은 노드에 대한 자식 노드가 2개 존재하는 경우
    // 인자로 전달받은 노드의 자식사이 간의 우선순위를 비교하여 우선순위가 높은 자식 노드의 Index값을 반환한다.
    else
    {

        if (pheap->arr[getLeftChildIndex(idx)].pr < pheap->arr[getRightChildIndex(idx)].pr)
            return getLeftChildIndex(idx);
        else
            return getRightChildIndex(idx);
    }
}

void Insert(Heap *pheap, Data pdata, Priority ppr)
{
    int insertIndex = (pheap->numOfData + 1);
    Element *newElment = (Element *)malloc(sizeof(Element));
    newElment->data = pdata;
    newElment->pr = ppr;

    while (1)
    {

        if (insertIndex == 1)
            break;
        if (newElment->pr > pheap->arr[getParentIndex(insertIndex)].pr)
            break;

        pheap->arr[insertIndex] = pheap->arr[getParentIndex(insertIndex)];
        insertIndex = getParentIndex(insertIndex);
    }

    pheap->arr[insertIndex] = *newElment;
    pheap->numOfData++;
}
Data Delete(Heap *pheap)
{
    Data returnElement = pheap->arr[1].data;
    Element lastElement = pheap->arr[pheap->numOfData];

    int parent = 1;
    int child;

    while (1)
    {

        if ((child = getPriorityOfChild(pheap, parent)) == 0)
            break;
        if (pheap->arr[child].pr > lastElement.pr)
            break;

        pheap->arr[parent] = pheap->arr[child];
        parent = child;
    }

    pheap->arr[parent] = lastElement;
    pheap->numOfData--;
    return returnElement;
}
