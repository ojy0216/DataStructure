#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int whichPrecede(Point p1, Point p2){
    if(p1.xpos < p2.xpos)
        return 0;
    else if(p1.xpos == p2.xpos && p1.ypos < p2.ypos)
        return 0;
    else
        return 1;
}

int main(){
    List list;
    Point compPos;
    Point *ppos;

    ListInit(&list);
    SetSortRule(&list, whichPrecede);

    ppos = (Point*)malloc(sizeof(Point));
    setPointPos(ppos, 4, 1);
    LInsert(&list, *ppos);

    ppos = (Point*)malloc(sizeof(Point));
    setPointPos(ppos, 2, 2);
    LInsert(&list, *ppos);

    ppos = (Point*)malloc(sizeof(Point));
    setPointPos(ppos, 3, 1);
    LInsert(&list, *ppos);

    ppos = (Point*)malloc(sizeof(Point));
    setPointPos(ppos, 3, 2);
    LInsert(&list, *ppos);

    printf("Number of data: %d\n", LCount(&list));

    if(LFirst(&list, ppos)){
        showPointPos(ppos);
        while(LNext(&list, ppos))
            showPointPos(ppos);
    }
    printf("\n");

    compPos.xpos = 2;
    compPos.ypos = 0;

    if(LFirst(&list, ppos)){
        if(PointComp(ppos, &compPos) == 1){
            *ppos = LRemove(&list);
            free(ppos);
        }
        while(LNext(&list, ppos)){
            if(PointComp(ppos, &compPos) == 1){
                *ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    printf("Number of data after removal: %d\n", LCount(&list));

    if(LFirst(&list, ppos)){
        showPointPos(ppos);
        while(LNext(&list, ppos))
            showPointPos(ppos);
    }
    printf("\n");

    return 0;
}