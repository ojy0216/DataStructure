#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2);

int main(){
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("Number of data: %d\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    if(LFirst(&list, &data)){
        if(data == 22)
            LRemove(&list);
        while(LNext(&list, &data)){
            if(data == 22)
                LRemove(&list);
        }
    }

    printf("Number of remaining data: %d\n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data))
            printf("%d ", data);
    }

    return 0;
}

int WhoIsPrecede(int d1, int d2){
    if(d1 < d2)
        return 0;
    else
        return 1;
}