#include <stdio.h>

void Swap(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int PivotSelect(int arr[], int left, int right){
    int lData = arr[left];
    int rData = arr[right];
    int mData = arr[(left + right) / 2];

    if(rData >= lData){
        if(mData >= rData)
            return rData; // l r m
        else
            return mData; // l m r
    }
    else{
        if(mData >= lData)
            return lData; // r l m
        else
            return mData; // r m l
    }
}

int Partition(int arr[], int left, int right){
    int pIdx = PivotSelect(arr, left, right);
    int pivot = arr[pIdx];

    int low = left + 1;
    int high = right;

    Swap(arr, left, pIdx);

    printf("Pivot: %d\n", pivot);

    while(low <= high){
        while(pivot >= arr[low] && low <= right)
            low++;

        while(pivot <= arr[high] && high >= (left + 1))
            high--;

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);

    return high;
}

void QuickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main(){
    int arr[15];
    for(int i = 0; i < 15; i++)
        arr[i] = i + 1;

    QuickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;
}