#include <stdio.h>
#include "ListBaseStack.h"

int main(){
    Stack stack;
    StackInit(&stack);

    for(int i = 0; i < 5; i++)
        SPush(&stack, i + 1);

    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
    
    return 0;
}