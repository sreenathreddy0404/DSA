#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target)return mid;
        if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int target = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ind = binarySearch(arr, n, target);
    if(ind!= -1){
        cout<<"present at index "<<ind;
    }else{
        cout<<"Not present in the array";
    }
}