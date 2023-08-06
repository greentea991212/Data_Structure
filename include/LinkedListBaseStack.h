#ifndef __LL_BASE_STACK_H__
#define __LL_BASE_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _LinkedListStack
{
    Node *head;
    int NumOfData;

} Stack;

void StackInit(Stack *pstack);
int IsEmpty(Stack *pstack);

void Push(Stack *pstack, Data data);
void Pop(Stack *pstack);
Data Peek(Stack *pstack);
int SCount(Stack *pstack);

#endif