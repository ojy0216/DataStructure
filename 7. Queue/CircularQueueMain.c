#include <stdio.h>
#include "CircularQueue.h"

int main(){
    Queue q;
    QueueInit(&q);

    for(int i = 0; i < 5; i++)
        Enqueue(&q, i + 1);

    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));

    return 0;
}