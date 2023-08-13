#ifndef __USEFULHEAP_HEAP_H__
#define __USEFULHEAP_HEAP_H__

typedef char Data;

#define TRUE 1
#define FALSE 0

#define LEN 100

typedef struct _heap
{
    int (*comp)(Data, Data); // 저장되어지는 데이터에 대한 우선순위를 결정해주는 함수 포인터--> 해당 함수 덕분에 사용자가 별도로 우선순위에 대한 데이터를 저장하지 않아도 된다.
    Data arr[LEN];
    int numOfData;
} Heap;

void HeapInit(Heap *pheap, int (*setPriorityFunc)(Data, Data));
void Insert(Heap *pheap, Data data);
Data Delete(Heap *pheap);
int IsEmpty(Heap *pheap);

#endif