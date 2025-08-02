#include <stdio.h>

int interpolationSearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        // Estimate the position of the target
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Check if target is at pos
        if (arr[pos] == target)
            return pos;

        // If target is greater, search in the right subarray
        if (arr[pos] < target)
            low = pos + 1;

        // If target is smaller, search in the left subarray
        else
            high = pos - 1;
    }

    // If target is not found
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    int result = interpolationSearch(arr, n, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
