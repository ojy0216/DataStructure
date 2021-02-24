#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2){
    return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pc){
    Heap heap;

    HeapInit(&heap, pc);

    for(int i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    for(int i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}

int main(){
    int arr[] = {3, 4, 2, 1};

    HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;
}