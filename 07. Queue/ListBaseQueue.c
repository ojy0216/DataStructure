#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq){
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue* pq){
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue* pq, Data data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }
    else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue* pq){
    Node* delNode;
    Data rData;

    if(QIsEmpty(pq)){
        printf("Queue Empty\n");
        exit(EXIT_FAILURE);
    }

    delNode = pq->front;
    rData = delNode->data;
    pq->front = delNode->next;

    free(delNode);

    return rData;
}

Data QPeek(Queue* pq){
    if(QIsEmpty(pq)){
        printf("Queue Empty\n");
        exit(EXIT_FAILURE);
    }

    return pq->front->data;
}