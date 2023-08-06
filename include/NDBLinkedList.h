#ifndef __NDB_LINKED_LIST_H_
#define __NDB_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *left;
    struct _node *right;

} Node;

typedef struct _NDBLinckedList
{

    Node *head;
    Node *curr;
    int NumOfData;

} List;

void ListInit(List *plist);
void ListInsert(List *plist, Data pdata);
int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
int LPrev(List *plist, Data *pdata);
int LCount(List *plist);

#endif