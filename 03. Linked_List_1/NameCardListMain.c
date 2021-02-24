#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(){
    List* plist = malloc(sizeof(List));
    NameCard* pcard;

    ListInit(plist);

    pcard = MakeNameCard("Alpha", "010-1234-5678");
    LInsert(plist, pcard);

    pcard = MakeNameCard("Bravo", "010-5678-1234");
    LInsert(plist, pcard);

    pcard = MakeNameCard("Charlie", "010-1111-2222");
    LInsert(plist, pcard);

    if(LFirst(plist, &pcard)){
        if(NameCompare(pcard, "Bravo") == 0)
            ShowNameCardInfo(pcard);
        else{
            while(LNext(plist, &pcard)){
                if(NameCompare(pcard, "Bravo") == 0){
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    if(LFirst(plist, &pcard)){
        if(NameCompare(pcard, "Charlie") == 0)
            ChangePhoneNum(pcard, "010-9999-9999");
        else{
            while(LNext(plist, &pcard)){
                if(NameCompare(pcard, "Charlie") == 0){
                    ChangePhoneNum(pcard, "010-9999-9999");
                    break;
                }
            }
        }
    }

    if(LFirst(plist, &pcard)){
        if(NameCompare(pcard, "Alpha") == 0){
            pcard = LRemove(plist);
            free(pcard);
        }
        else{
            while(LNext(plist, &pcard)){
                if(NameCompare(pcard, "Alpha") == 0){
                    pcard = LRemove(plist);
                    free(pcard);
                    break;
                }
            }
        }
    }

    printf("\n%d\n", LCount(plist));
    if(LFirst(plist, &pcard)){
        ShowNameCardInfo(pcard);
        while(LNext(plist, &pcard))
            ShowNameCardInfo(pcard);
    }

    free(plist);

    return 0;
}