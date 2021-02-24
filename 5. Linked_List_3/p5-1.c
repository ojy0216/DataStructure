#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p5-1.h"
#include "CLinkedList.h"

Info* getDutyPerson(List* plist, char* name, int day){
    int order, i;
    Info *tmp = malloc(sizeof(Info));

    if(LFirst(plist, tmp)){
        if(strcmp(tmp->name, name) == 0){
            for(int i = 0; i < day; i++){
                LNext(plist, tmp);
            }
            return tmp;
        }
        
        for(int i = 0; i < LCount(plist) - 1; i++){
            if(LNext(plist, tmp)){
                if(strcmp(tmp->name, name) == 0){
                    for(int j = 0; j < day; j++){
                        LNext(plist, tmp);
                    }
                    return tmp;
                }
            }
        }
    }
    
    strcpy(tmp->name,"Failed");
    return tmp;
}

int main(){
    List list;
    Info info;  
    Info* duty;
    
    ListInit(&list);

    strcpy(info.name, "A");
    info.id = 1;
    LInsert(&list, info);

    strcpy(info.name, "B");
    info.id = 2;
    LInsert(&list, info);

    strcpy(info.name, "C");
    info.id = 3;
    LInsert(&list, info);

    strcpy(info.name, "D");
    info.id = 4;
    LInsert(&list, info);

    if(LFirst(&list, &info)){
        printf("%s ", info.name);
        
        for(int i = 0; i < LCount(&list) - 1; i++){
            if(LNext(&list, &info))
                printf("%s ", info.name);
        }
    }
    printf("\n");

    duty = getDutyPerson(&list, "C", 3);
    printf("%s\n",duty->name);

    free(duty);    

    return 0;
}
