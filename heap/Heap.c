#include <stdio.h>
#include <stdlib.h>
#include "../include/Heap.h"

void HeapInit(Heap *heap)
{

    // heap을 구현하기 위한 배열에서 편의성을 위해 idx 0자리는 비워둔다.
    heap->numOfData = 0;
}

int IsEmpty(Heap *heap)
{

    if (heap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int IsFull(Heap *heap)
{

    if (heap->numOfData == HEAP_LEN - 1)
        return TRUE;
    else
        return FALSE;
}

int GetParentIndex(int idx)
{

    return idx / 2;
}

int GetLeftChildIndex(int idx)
{

    return idx * 2;
}

int GetRightChildIndex(int idx)
{

    return idx * 2 + 1;
}

int GetPriorityChild(Heap *heap, int parentIdx)
{

    // 자식노드가 있는지 없는지
    // 자식노드기 하나인지 아닌지
    // 자식노드가 두개라면 조건판단.
    // 자식노드 유무 판단은 인덱스 값으로 판별한다.
    if (heap->numOfData < GetLeftChildIndex(parentIdx))
        return 0;
    else if (heap->numOfData == GetLeftChildIndex(parentIdx))
    {
        return GetLeftChildIndex(parentIdx);
    }
    else
    {
        if (heap->arr[GetLeftChildIndex(parentIdx)].data < heap->arr[GetRightChildIndex(parentIdx)].data)
            return GetLeftChildIndex(parentIdx);
        else
            return GetRightChildIndex(parentIdx);
    }
}

void Insert(Heap *heap, char data)
{

    /*
    트리에서의 맨마지막 인덱스에 삽입한다.
    그 이후, 현재 위치에서의 부모와 비교 해가며 자리를 옮겨간다.
    */
    int insertIndex = heap->numOfData + 1; // 새로 삽입할 인덱스 설정

    Element newElement = {data}; // 일단은 노드 생성

    while (insertIndex != 1 && heap->arr[GetParentIndex(insertIndex)].data > data)
    {
        heap->arr[insertIndex] = heap->arr[GetParentIndex(insertIndex)];
        insertIndex = GetParentIndex(insertIndex);
    }

    heap->arr[insertIndex] = newElement;
    heap->numOfData++;

    return;
}

Element Delete(Heap *heap)
{
    Element delData = heap->arr[1]; // 우선적으로 삭제해야 할 데이터를 백업해둔다.

    int currentIndex = 1;
    Element lastElemnt = heap->arr[heap->numOfData]; // 맨 마지막에 저장된 노드
                                                     // printf("current idx : %d\n", currentIndex);
    while (heap->arr[GetPriorityChild(heap, currentIndex)].data < lastElemnt.data)
    {
        heap->arr[currentIndex] = heap->arr[GetPriorityChild(heap, currentIndex)];
        if (currentIndex = GetPriorityChild(heap, currentIndex)) // currentIndex를 갱신함과 동시에, 0이되면 멈추게 한다.
            break;
        // printf("current idx : %d\n", currentIndex);
        // printf("numOf Data : %d\n", heap->numOfData);
    }

    heap->arr[currentIndex] = lastElemnt;
    heap->numOfData--;

    return delData;
}