#ifndef __D_LINKED_LIST_H
#define __D_LINKED_LIST_H

#define TRUE 1
#define FALSE 0

typedef int DATA;

typedef struct node
{

    struct node *next;
    DATA data;

} Node;

typedef struct _linkedList
{
    Node *head;
    Node *curr;
    Node *prev;
    int numOfData;
    int (*comp)(struct _linkedList *, int);

} List;

void ListInit(List *plist);
void ListInsert(List *plist, DATA Ldata);
void FInsert(List *plist, DATA Ldata); // head를 기준으로 즉, 앞부분에 노드를 추가하는 방식

/*
리스트에 저장된 데이터를 조회하는 함수
*/
int LFirst(List *plist, DATA *Ldata); // 리스트의 첫 번째 데이터 존재유무 확인
int LNext(List *plist, DATA *Ldata);  // 리스트의 다음 노드에 대한 존재 유무 확인
/*
 */

int LRemove(List *plist);
int LCount(List *plist);

#endif