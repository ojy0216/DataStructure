#include <stdio.h>
#include "string.h"
#include "PriorityQueue.h"

int DataPriorityComp(char c1[], char c2[]){
    return strlen(c2) - strlen(c1);
}

int main(){
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "abcd");
    PEnqueue(&pq, "abcde");
    PEnqueue(&pq, "abc");

    while(!PQIsEmpty(&pq))
        printf("%s\n", PDequeue(&pq));

    return 0;
}