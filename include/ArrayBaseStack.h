#ifndef __AB_STACK_H
#define __AB_STACK_H

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int DataType;

typedef struct _arrayStack
{
    DataType arr[STACK_LEN];
    int top;

} Stack;

void StackInit(Stack *p);
void StackPush(Stack *p, DataType data);
void StackPop(Stack *p);
DataType StackPeek(Stack *p);
int StackSize(Stack *p);

#endif