#include <stdio.h>
#include "../include/ArrayBaseStack.h"

void StackInit(Stack *p)
{
    p->top = -1;
}

void StackPush(Stack *p, DataType data)
{
    p->top++;
    p->arr[p->top] = data;
}

void StackPop(Stack *p)
{

    p->top--;
}

DataType StackPeek(Stack *p)
{

    return p->arr[p->top];
}

int StackSize(Stack *p)
{

    return p->top;
}

int IsEmpty(Stack *p)
{

    if (p->top == -1)
        return TRUE;
    else
        return FALSE;
}