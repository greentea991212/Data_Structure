#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    Data data;

} Node;

typedef struct _deque
{
    Node *head;
    Node *tail;
    int numOfData;

} Deque;

void DequeInit(Deque *pdeq);
void addFirst(Deque *pdeq, Data pdata);
void addLast(Deque *pdeq, Data pdata);

Data removeFirst(Deque *pdeq);
Data removeLast(Deque *pdeq);
Data peekFirst(Deque *pdeq);
Data peekLast(Deque *pdeq);

int isEmpty(Deque *pdeq);

#endif