#include <stdio.h>

void SelSort(int arr[], int n){
    int minIdx;
    int tmp;

    for(int i = 0; i < n - 1; i++){
        minIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

int main(){
    int arr[] = {3, 2, 4, 1};

    SelSort(arr, sizeof(arr) / sizeof(int));
    
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);

    return 0;

}