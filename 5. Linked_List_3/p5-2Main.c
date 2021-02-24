#include <stdio.h>
#include "p5-2.h"

int main(){
    List list;
    int data;

    ListInit(&list);

    for(int i = 0; i < 5; i++)
        LInsert(&list, i + 1);
    
    if(LFirst(&list, &data)){
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    if(LFirst(&list, &data)){
        if(data % 2 == 0)
            LRemove(&list);
        
        while(LNext(&list, &data)){
            if(data % 2 == 0)
                LRemove(&list);
        }
    }

    if(LFirst(&list, &data)){
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }

    return 0;
}