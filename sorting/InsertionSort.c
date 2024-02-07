/*
삽입(Insertion)정렬이란?
마치 손에 쥐고있는 카드를 하나씩 정렬해가는 것과 유사하다.
정렬안된 원소를 정렬된 부분에 대해서 올바를 위치에 하나씩 삽입하는 방법

기본 알고리즘
데이터를 한칸씩 밀면서 삽입할 위치를 찾는다.
*/

#include <stdio.h>

void InsertionSort(int *arr, int len);

int main()
{

    int arr[5] = {10, 9, 21, 15, 100};
    int len = sizeof(arr) / sizeof(int);
    InsertionSort(arr, len);

    for (int i = 0; i < len; i++)
    {

        printf("%d ", arr[i]);
    }
    return 0;
}

void InsertionSort(int *arr, int len)
{
    int j;
    for (int i = 1; i < len; i++)
    {

        int insertData = arr[i];
        for (j = i - 1; j >= 0; j--)
        {

            if (arr[j] > insertData)
            {

                arr[j + 1] = arr[j];
            }
            else
                break; // 삽입할 자리, 즉 insertData보다 작은 값을 찾았음으로 반복문을 종료한다.
        }
        arr[j + 1] = insertData;
    }
}