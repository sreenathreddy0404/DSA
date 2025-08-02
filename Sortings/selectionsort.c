#include <stdio.h>

void selectionSort(int arr[], int n){
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++){
        minIdx = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
