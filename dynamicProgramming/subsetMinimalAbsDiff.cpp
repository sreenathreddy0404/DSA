#include <bits/stdc++.h>
using namespace std;

int isTargetThereT(int arr[], int n, int target){
    vector<bool> prev(target + 1, false);

    prev[0] = true;
    if (arr[0] <= target)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++){
        vector<bool> curr(target + 1, false);
        for (int k = 0; k <= target; k++){
            bool notTake = prev[k];
            bool take = false;
            if (arr[i] <= k){
                take = prev[k - arr[i]];
            }
            curr[k] = take || notTake;
        }
        prev = curr;
    }

    int mini = INT_MAX;
    for(int i=0;i<=target;i++){
        if(prev[i]){
            int diff = abs(target -2*i);
            mini = min(mini,diff);
        }
    }
    return mini;
}
int findMinAbsDifference(int arr[],int n){

    int totSum = 0;
    for (int i = 0; i < n; i++){
        totSum += arr[i];
    }
    return isTargetThereT(arr,n,totSum);
}

int main(){
    int arr[] = {1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Minimum Absolute difference between two subsets is eqaul to "<<findMinAbsDifference(arr,n);
}