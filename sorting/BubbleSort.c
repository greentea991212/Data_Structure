// ���� ������ �־��� ���� ������, ���� ū ���� �ǵڷ� ������ ���ı���̴�.
/*
�� Bubble �����̶�� �ұ�?
�յ� �迭 ���ҵ��� ���� ���Ͽ� �ٲٴ� �۾��� ��ǰ�� ����Ű�� �Ͱ� �����Ͽ� ���� �����̶�� �Ѵ�.
�յ� ���ҵ��� ���Ͽ� �����ϴ� ����, �־��� ���� ������ ���� ū ���� �ڿ������� �ǵڿ� ���� �ȴ�.
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