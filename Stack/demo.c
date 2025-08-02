#include<stdio.h>
void modify(int arr[]){
    arr[0] = 5;
}
int main(){
    int n = 5;
    int arr[5] = {10,20,30,40,50};
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    modify(arr);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}