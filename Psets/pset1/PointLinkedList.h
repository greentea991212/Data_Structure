#ifndef __POINT_LINKED_LIST_H_
#define __POINT_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef struct _point
{

    int xpos;
    int ypos;

} Point;

typedef struct _node
{

    Point data;
    struct _node *next;

} Node;

typedef struct _linkedList
{
    Node *head;
    Node *curr;
    Node *prev;
    int (*comp)(Point *, Point *);
    int NumOfData;

} List;

void ListInit(List *plist);
void ListInsert(List *plist, Point *data);

int LCount(List *plist);
void LSearch(List *plist);

void SetSortRule(List *plist, int (*comp)(Point *, Point *));

Point *PointInit();
void setPoint(Point *point, int x, int y);

#endif