// ���� (Selection Sort)���� �����, �־��� ���� ������ ���� ���� ���� ã�Ƴ�� �Ǿ����� ��ġ�ϵ��� �� �Ѵ�.
// �񱳸� ���� �ּڰ��� Ž���Ѵ�.
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
        minIndex = i; // ���� ��ġ�� ����� �ε��� ����

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