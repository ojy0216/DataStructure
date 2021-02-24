#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen){
    Queue buckets[BUCKET_NUM];
    int di;
    int divfac = 1;
    int radix;

    for(int bi = 0; bi < BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]);

    for(int pos = 0; pos < maxLen; pos++){
        for(di = 0; di < num; di++){
            radix = (arr[di] / divfac) % 10;
            Enqueue(&buckets[radix], arr[di]);
        }

        di = 0;
        for(int bi = 0; bi < BUCKET_NUM; bi++){
            while(!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }

        divfac *= 10;
    }
}

int main(){
    int arr[] = {13, 212, 14, 7141, 10987, 6, 15};

    RadixSort(arr, sizeof(arr) / sizeof(int), 5);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;
}