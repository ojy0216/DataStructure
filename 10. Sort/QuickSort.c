#include <stdio.h>

void Swap(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

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
    int arr[] = {3, 2, 4, 1, 7, 6, 5};
    // int arr[] = {3, 3, 3};

    QuickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;
}