#ifndef __P6_1_H__
#define __p6_1_H__

#include "CLinkedList.h"

typedef int Data;

typedef CList Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);
#endif