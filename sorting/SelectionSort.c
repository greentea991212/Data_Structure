// 선택 (Selection Sort)정렬 기법은, 주어진 범위 내에서 가장 작은 값을 찾아내어서 맨앞으로 위치하도록 끔 한다.
// 비교를 통해 최솟값을 탐색한다.
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *arr, int len);

int main()
{

    int arr[5] = {10, 9, 21, 15, 100};
    int len = sizeof(arr) / sizeof(int);
    SelectionSort(arr, len);

    for (int i = 0; i < len; i++)
    {

        printf("%d ", arr[i]);
    }
    return 0;
}

void SelectionSort(int *arr, int len)
{

    int minIndex;
    int temp;

    for (int i = 0; i < len - 1; i++)
    {
        minIndex = i; // 현재 위치에 저장될 인덱스 설정

        for (int j = i + 1; j < len; j++)
        {
            if (arr[minIndex] > arr[j])
            {

                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}