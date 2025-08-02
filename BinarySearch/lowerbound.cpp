#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=target){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}


int main(){
    int arr[] = {1,2,2,2,2,6};
    int target = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ind = upperBound(arr, n, target);
    if(ind!= -1){
        cout<<"present at index "<<ind;
    }else{
        cout<<"Not present in the array";
    }
}