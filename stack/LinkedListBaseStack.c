#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListBaseStack.h"

// Use Dummy Node

void StackInit(Stack *pstack)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    pstack->head = newNode;
}

int IsEmpty(Stack *pstack)
{

    if (pstack->head->next == NULL)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack *pstack, Data data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head->next;
    pstack->head->next = newNode;

    (pstack->NumOfData)++;
}

void Pop(Stack *pstack)
{
    if (IsEmpty(pstack))
    {

        printf("Stack is empty\n");
        return;
    }

    Node *delNode = pstack->head->next;
    pstack->head->next = pstack->head->next->next;
    free(delNode);
    (pstack->NumOfData--);
}

Data Peek(Stack *pstack)
{
    return pstack->head->next->data;
}

int SCount(Stack *pstack)
{

    return pstack->NumOfData;
}