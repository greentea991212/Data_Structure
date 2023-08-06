#ifndef __DB_LINKED_LIST_H_
#define __DB_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *left;
    struct _node *right;

} Node;

typedef struct _DBLinckedList
{

    Node *head;
    Node* tail;
    Node *curr;
    int NumOfData;

} List;

void ListInit(List *plist);
void ListInsert(List *plist, Data pdata);
int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
int LPrev(List *plist, Data *pdata);
Data LRemove(List* plist);
int LCount(List *plist);

#endif