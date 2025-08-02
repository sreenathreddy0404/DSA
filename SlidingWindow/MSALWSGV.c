//Minimum Sub Array Length where sum is greater than a value
#include<stdio.h>
#include<limits.h>

int findMinLen(int arr[],int n,int x){
    int sum = 0;
    int minlen = INT_MAX;
    int start = 0;
    int end = 0;
    while(end<n){
        while(sum<=x && end<n){
            sum += arr[end++];
        }
        while(sum>x && start<end){
            if(minlen > (end-start)){
                minlen = end-start;
            }
            sum -= arr[start++];
        }
    }
    return minlen;
}
int main(){
    int arr[] = {1,4,45,6,10,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = 51;
    printf("minimum sub array length %d\n",findMinLen(arr,size,x));
    int arr2[] = {1, 10, 5, 2, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    x = 9;
    printf("minimum sub array length %d\n", findMinLen(arr2, size2, x));

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    x = 280;
    printf("minimum sub array length %d\n", findMinLen(arr3, size3, x));
}