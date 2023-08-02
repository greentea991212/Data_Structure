#include <stdio.h>
#include <stdlib.h>
#include "PointLinkedList.h"

void ListInit(List *plist)
{

    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->curr = NULL;
    plist->prev = NULL;
    plist->comp = NULL;
    plist->NumOfData = 0;
}

void ListInsert(List *plist, Point *data)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = *data;
    newNode->next = NULL;
    (plist->NumOfData)++;

    plist->curr = plist->head;

    while (plist->curr->next != NULL && (plist->comp(&(plist->curr->next->data), data)))
    {

        plist->curr = plist->curr->next;
    }

    newNode->next = plist->curr->next;
    plist->curr->next = newNode;
}

int LCount(List *plist)
{

    return plist->NumOfData;
}

void LSearch(List *plist)
{

    plist->curr = plist->head;

    if (plist->head->next == NULL)
    {

        printf("리스트에 데이터가 존재하지 않습니다.\n");
        return;
    }
    else
    {
        plist->curr = plist->head->next;
        while (1)
        {

            printf(" (%d . %d) ", plist->curr->data.xpos, plist->curr->data.ypos);
            plist->curr = plist->curr->next;
            if (plist->curr->next == NULL)
                break;
        }
    }
}

void SetSortRule(List *plist, int (*comp)(Point *, Point *))
{

    plist->comp = comp;
}

Point *PointInit()
{

    Point *p = (Point *)malloc(sizeof(Point));

    p->xpos = 0;
    p->ypos = 0;

    return p;
}

void setPoint(Point *point, int x, int y)
{

    point->xpos = x;
    point->ypos = y;
}
