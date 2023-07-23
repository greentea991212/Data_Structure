#include <stdio.h>
#include <stdlib.h>
#include "../include/ArrayBaseQueue.h"

int main(void)
{

    Queue *q = (Queue *)malloc(sizeof(Queue));

    QInit(q);

    printf("Input some data in Queue!\n");
    printf(".......\n");

    // 원형 큐는 배열의 한 자리를 이용하지 않는 것을 원칙으로 하기 때문에
    // 배열 크기 - 1 만큼의 반복문을 통해 데이터를 삽입한다.
    // 때문에 배열에 삽입되어지는 데이터는 1,2,3,4가 될 것이다.
    for (int i = 0; i < Q_SIZE - 1; i++)
    {
        Enqueue(q, i + 1);
    }

    printf("What is first element of Queue? => ");
    printf("%d\n\n", QPeek(q));
    printf("Deleting a first element...\n");
    Dequeue(q);
    printf("What is second element of Queue? => ");
    printf("%d\n\n", QPeek(q));
    printf("What is size of Queue? => ");
    printf("%d\n", QSize(q));
    Dequeue(q);
    Dequeue(q);
    printf("What is last element of Queue? => ");
    printf("%d\n\n", QPeek(q));
    Dequeue(q);
    printf("Is Queue Empty? => ");
    if (IsEmpty(q))
        printf("Yes!\n");
    else
        printf("No!\n");

    return 0;
}