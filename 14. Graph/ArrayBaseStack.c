#include <stdio.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack){
    pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack){
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack* pstack, Data data){
    (pstack->topIndex)++;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack){
    int rIdx;

    if(SIsEmpty(pstack)){
        printf("Memory Error\n");
        return -1;
    }
    
    rIdx = pstack->topIndex;
    (pstack->topIndex)--;

    return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack){
    if(SIsEmpty(pstack)){
        printf("Memory Error\n");
        return -1;
    }

    return pstack->stackArr[pstack->topIndex];
}