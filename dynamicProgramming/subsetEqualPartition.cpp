#include <bits/stdc++.h>
using namespace std;

bool isTargetThereT(int arr[], int n, int target){
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;

    if (arr[0] <= target) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++){
        for (int k = 0; k <= target; k++){
            bool notTake = dp[i - 1][k];
            bool take = false;
            if (arr[i] <= k) take = dp[i - 1][k - arr[i]];
            dp[i][k] = take || notTake;
        }
    }
    return dp[n - 1][target];
}

bool checkEqualPartition(int arr[],int n){
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }

    if(totSum%2 == 1)return false;

    int target = totSum/2;

    return isTargetThereT(arr,n-1,target);
}


int main(){
    int arr[] = {1,1,9,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"is there a pratition of two subset with equal sum "<<checkEqualPartition(arr,n);
}