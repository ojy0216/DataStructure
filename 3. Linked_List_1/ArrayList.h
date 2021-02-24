#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
// for PointListMain.c
// #include "Point.h"
// for NameCardListMain.c
#include "NameCard.h"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

// for ListMain.c, p3-1.c
// typedef int LData;
// for PointListMain.c
// typedef Point LData;
// for NameCardListMain.c
typedef NameCard* LData;

typedef struct _ArrayList{
    LData arr[LIST_LEN];
    int numOfData, curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif