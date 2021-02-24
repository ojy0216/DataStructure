#include <stdio.h>
#include "p6-1.h"

void StackInit(Stack* pstack){
    ListInit(pstack);
}

int SIsEmpty(Stack* pstack){
    if(LCount(pstack) == 0)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack* pstack, Data data){
    LInsertFront(pstack, data);
}

Data SPop(Stack* pstack){
    Data rdata;
    
    if(SIsEmpty(pstack)){
        printf("Stack Empty\n");
        return -1;
    }

    if(LFirst(pstack, &rdata))
        rdata = LRemove(pstack);

    return rdata;
}

Data SPeek(Stack* pstack){
    Data data;

    if(SIsEmpty(pstack)){
        printf("Memory Error\n");
        return -1;
    }

    LFirst(pstack, &data);

    return data;
}

