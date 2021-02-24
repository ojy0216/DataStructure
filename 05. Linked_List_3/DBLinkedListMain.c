#include <stdio.h>
#include "DBLinkedList.h"

int main(){
    List list;
    int data;

    ListInit(&list);

    for(int i = 0; i < 8; i++)
        LInsert(&list, i + 1);

    if(LFirst(&list, &data)){
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);

        while(LPrevious(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
}