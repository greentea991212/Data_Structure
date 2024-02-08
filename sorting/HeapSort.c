#include <stdlio.h>

// 주어진 데이터(배열)에 대해서 힙을 구성해야 된다.
// 힙은 데이터의 중복을 허락한다.
// 힙은 완전 이진 트리이다.

void Swap(int *arr, int data1, int data2);
void Heapify(int *arr, int index);

void Swap(int *arr, int data1, int data2)
{
    int temp = arr[data2];
    arr[data2] = arr[data1];
    arr[data1] = temp;
}

void Heapify(int *arr, int parent)
{
    int leftChild = parent * 2;
    int rightChild = parent * 2 + 1;
    int numOfData = sizeof(arr) / sizeof(int);
    // 1. 왼쪽 자식과 오른쪽 자식을 비교한다.
    // 2. 해당 결과를 부모와 비교한다.
    // 3. 만약 자식의 우선순위가 더 높다면, 자식과 부모를 서로 바꾼다.
    // (메인 함수에서 현재 함수로 넘어올때, 자식 노드가 없을 경우는 없겠지만 오른쪽 자식이 없을 경우는 있을것이다.)
    int swapChild;

    if (arr[leftChild] < arr[rightChild])
    {
        swapChildIndex = leftChild;
    }
    else // 오른쪽의 우선순위가 더 높은 경우
    {
        swapChildIndex = rightChild;
    }
}
