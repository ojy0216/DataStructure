#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main(){
    List *plist = malloc(sizeof(List));
    LData data;
    int sum;

    ListInit(plist);

    for(int i = 1; i <= 9; i++)
        LInsert(plist, i);

    if(LFirst(plist, &data)){
        printf("%d ", data);
        while(LNext(plist, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    if(LFirst(plist, &data)){
        sum += data;
        while(LNext(plist, &data))
            sum += data;
    }

    if(LFirst(plist, &data)){
        if((data % 2) == 0 || (data % 3) == 0)
            LRemove(plist);
        while(LNext(plist, &data)){
            if((data % 2) == 0 || (data % 3) == 0)
                LRemove(plist);
        }
    }

    if(LFirst(plist, &data)){
        printf("%d ", data);
        while(LNext(plist, &data))
            printf("%d ", data);
    }

    free(plist);

    return 0;
}