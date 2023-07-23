#include <stdio.h>
#include <stdlib.h>
#include "../include/ArrayBaseStack.h"

int main()
{

    Stack *s = (Stack *)malloc(sizeof(Stack));

    StackInit(s);

    for (int i = 0; i < 5; i++)
    {

        StackPush(s, i + 1);
    }

    for (int i = 0; i < 5; i++)
    {

        printf("%d ", StackPeek(s));
        StackPop(s);
    }
}