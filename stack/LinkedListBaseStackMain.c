#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListBaseStack.h"

int main(void)
{

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    StackInit(stack);

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    Push(stack, 6);

    while (!IsEmpty(stack))
    {

        printf("%d ", Peek(stack));
        Pop(stack);
    }
    printf("\n");

    return 0;
}