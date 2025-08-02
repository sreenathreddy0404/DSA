#include <stdio.h>
void partition(int arr[], int low, int high);
void mergesort(int arr[], int low, int mid, int high);
int main()
{
    int arr[] = {4, 2, 5, 9, 3, 6, 1};
    int i, j, n = 7;
    printf("Before sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    partition(arr, 0, n - 1);
    printf("After sorting  : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void partition(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergesort(arr, low, mid, high);
    }
}
void mergesort(int arr[], int low, int mid, int high)
{
    int l, r, i, j, k;
    l = mid - low + 1;
    r = high - mid;
    int left[l], right[r];
    for (i = 0; i < l; i++)
    {
        left[i] = arr[low + i];
    }
    for (j = 0; j < r; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    i = j = 0;
    k = low;
    while (i < l && j < r)
    {
        if (left[i] > right[j])
        {
            arr[k] = right[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = left[i];
            k++;
            i++;
        }
    }
    while (i < l)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < r)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}