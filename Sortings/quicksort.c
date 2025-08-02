#include <stdio.h>
int quicksort(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] < pivot && i < high)
        {
            i++;
        }
        while (arr[j] >= pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void partition(int *arr, int low, int high)
{
    if (low < high)
    {
        int PI = quicksort(arr, low, high);
        partition(arr, low, PI-1);
        partition(arr, PI + 1, high);
    }
}
int main()
{
    int arr[] = {1, 9, 4, 3, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    partition(arr, 0, n - 1);
    printf("After  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
