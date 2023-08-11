/*
Using array for Implement priority queue
*/

#ifndef __SIMPLE_HEAP_H_
#define __SIMPLE_HEAP_H_

#define TRUE 1
#define FALSE 0

#define LEN 100

typedef int Priority; // 해당 정수의 값이 작을 수록 높은 우선순위를 의미
typedef char Data;    // 실질적으로 저장되는 데이터

typedef struct _element
{
    Data data;
    Priority pr;

} Element;

typedef struct _heap
{
    Element arr[LEN]; // index 0자리는 데이터를 비워둘 것이다.
    int numOfData;    // 때문에 마지막으로 저장된 데이터의 index와 동일하다.

} Heap;

void HeapInint(Heap *pheap);

void Insert(Heap *pheap, Data pdata, Priority ppr);
Data Delete(Heap *pheap);

int IsEmpty(Heap *pheap);

#endif
