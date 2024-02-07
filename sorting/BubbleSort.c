// 버블 정렬은 주어진 범위 내에서, 제일 큰 값을 맨뒤로 보내는 정렬기법이다.
/*
왜 Bubble 정렬이라고 할까?
앞뒤 배열 원소들을 서로 비교하여 바꾸는 작업이 거품을 일으키는 것과 유사하여 버블 정렬이라고 한다.
앞뒤 원소들을 비교하여 정렬하다 보면, 주어진 범위 내에서 가장 큰 값이 자연스럽게 맨뒤에 오게 된다.
*/
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr, int len);

int main()
{

    int arr[5] = {10, 4, 3, 44, 100};
    int len = sizeof(arr) / sizeof(int);

    BubbleSort(arr, len);

    for (int i = 0; i < len; i++)
    {

        printf("%d ", arr[i]);
    }
    return 0;
}

void BubbleSort(int *arr, int len)
{
    int temp = 0;

    for (int i = 0; i < len - 1; i++)
    {

        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}