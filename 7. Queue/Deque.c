#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq){
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq){
    if(pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;

    if(DQIsEmpty(pdeq)){
        newNode->next = NULL;

        pdeq->head = newNode;
        pdeq->tail = newNode;
    }
    else{
        newNode->next = pdeq->head;

        pdeq->head->prev = newNode;
        pdeq->head = newNode;
    }
}

void DQAddLast(Deque* pdeq, Data data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(DQIsEmpty(pdeq)){
        newNode->prev = NULL;

        pdeq->head = newNode;
        pdeq->tail = newNode;
    }
    else{
        newNode->prev = pdeq->tail;

        pdeq->tail->next = newNode;
        pdeq->tail = newNode;
    }
}

Data DQRemoveFirst(Deque* pdeq){
    Node* rNode;
    Data rData;

    if(DQIsEmpty(pdeq)){
        printf("Deque Empty\n");
        exit(EXIT_FAILURE);
    }

    rNode = pdeq->head;
    rData = rNode->data;

    if(pdeq->head->next == NULL){
        pdeq->head = NULL;
    }
    else{
        pdeq->head->next->prev = NULL;
        pdeq->head = pdeq->head->next;
    }

    free(rNode);

    return rData;
}

Data DQRemoveLast(Deque* pdeq){
    Node* rNode;
    Data rData;

    if(DQIsEmpty(pdeq)){
        printf("Deque Empty\n");
        exit(EXIT_FAILURE);
    }

    rNode = pdeq->tail;
    rData = rNode->data;

    if(pdeq->tail->prev == NULL){
        pdeq->tail = NULL;
    }
    else{
        pdeq->tail->prev->next = NULL;
        pdeq->tail = pdeq->tail->prev; 
    }

    free(rNode);

    return rData;
}

Data DQGetFirst(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("Deque Empty\n");
        exit(EXIT_FAILURE);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq){
    if(DQIsEmpty(pdeq)){
        printf("Deque Empty\n");
        exit(EXIT_FAILURE);
    }

    return pdeq->tail->data;
}