#include <stdio.h>
#include <stdlib.h>
#include "p5-2.h"

void ListInit(List* plist){
    plist->head = malloc(sizeof(Node));
    plist->tail = malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->numOfData = 0;
}

void LInsert(List* plist, Data data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata){
    if(plist->head->next == plist->tail)
        return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List* plist, Data* pdata){
    if(plist->cur->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

Data LRemove(List* plist){
    Node* rnode = plist->cur;
    Data rdata = plist->cur->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;

    (plist->numOfData)--;

    free(rnode);
    
    return rdata;
}

int LCount(List* plist){
    return plist->numOfData;
}