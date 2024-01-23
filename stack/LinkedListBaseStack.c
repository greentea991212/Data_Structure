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
    /*
    가장 먼저 삭제해야할 데이터를 head가 가르키도록 한다.
    즉, 새로운 data를 tail이 아닌, head에 추가한다.
    */
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head->next;
    pstack->head->next = newNode;

    (pstack->NumOfData)++;
}

void Pop(Stack *pstack)
{   
    /*
    삭제할 때에는 head를 오른쪽으로 옮기면서 삭제한다.
    */
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