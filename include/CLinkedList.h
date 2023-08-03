#ifndef __C_LINKED_LIST_H_
#define __C_LINKED_LIST_H_

typedef int Data;

#define TRUE 1
#define FALSE 0

typedef struct _node
{
    Data data;
    struct _node *next;

} Node;

typedef struct _CLinkedList
{
    Node *tail;
    Node *curr;
    Node *prev;

    int NumOfData;

} CList;

void ListInit(CList *plist);
void ListInsertTail(CList *plist, Data pdata);
void ListInsertFront(CList *plist, Data pdata);

int LFirst(CList *plist, Data* pdata);
int LNext(CList *plist, Data* pdata);

int LCount(CList *plist);

Data LRemove(CList *plist);

#endif
