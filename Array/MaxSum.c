#include<stdio.h>
#include<limits.h>
void findMaxSum(int arr[],int n,int target){
    int sum = arr[0];
    int maxlen = INT_MAX;
    int i = 0;
    int j = 0;
    int maxsumarr[2]={-1};
    while(j<n){
        j++;
        sum = sum + arr[j];
        if(sum == target){
            if(maxlen>j-i+1){
                maxsumarr[0] = i;
                maxsumarr[1] = j;
                maxlen = j-i+1;
            }
            j++;
            sum = sum + arr[j];
        }  
        else{
            while(sum>target){
                sum = sum - arr[i];
                i++;
            } 
        }
    }
    if(maxlen == 0){
        printf("no sub array found");
    }else{
        printf("sum found between indexes %d and %d",maxsumarr[0],maxsumarr[1]);
    }
}
int main(){
    int arr[] = {1,3,0,0,3,2,7};
    findMaxSum(arr,7,7);
}