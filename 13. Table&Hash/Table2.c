#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table* pt, HashFunc* f){
    for(int i = 0; i < MAX_TBL; i++)
        ListInit(&(pt->tbl[i]));

    pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v){
    int hv = pt->hf(k);
    Slot newSlot = {k, v};

    if(TBLSearch(pt, k) != NULL){
        printf("Key Overrided\n");
        return;
    }
    else
        LInsert(&(pt->tbl[hv]), newSlot);
}

Value TBLDelete(Table* pt, Key k){
    int hv = pt->hf(k);
    Slot cSlot;

    if(LFirst(&(pt->tbl[hv]), &cSlot)){
        if(cSlot.key == k){
            LRemove(&(pt->tbl[hv]));
            return cSlot.value;
        }
        else{
            while(LNext(&(pt->tbl[hv]), &cSlot)){
                if(cSlot.key == k){
                    LRemove(&(pt->tbl[hv]));
                    return cSlot.value;
                }
            }
        }
    }

    return NULL;
}

Value TBLSearch(Table* pt, Key k){
    int hv = pt->hf(k);
    Slot cSlot;

    if(LFirst(&(pt->tbl[hv]), &cSlot)){
        if(cSlot.key == k)
            return cSlot.value;
        else{
            while(LNext(&(pt->tbl[hv]), &cSlot)){
                if(cSlot.key == k)
                    return cSlot.value;
            }
        }
    }

    return NULL;
}