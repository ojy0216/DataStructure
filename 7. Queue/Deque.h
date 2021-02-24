#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node* prev;
    struct _node* next;
} Node;

typedef struct _dlDeque{
    Node* head;
    Node* tail;
} DLDqueue;

typedef DLDqueue Deque;

void DequeInit(Deque* pdeq);
int DQIsEmpty(Deque* pdeq);

void DQAddFirst(Deque* pdeq, Data data);
void DQAddLast(Deque* pdeq, Data data);

Data DQRemoveFirst(Deque* pdeq);
Data DQRemoveLast(Deque* pdeq);

Data DQGetFirst(Deque* pdeq);
Data DQGetLast(Deque* pdeq);

#endif