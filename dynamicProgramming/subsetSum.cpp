#include <bits/stdc++.h>
using namespace std;

bool isTargetThere(int arr[],int n,int target){
    if (target == 0) return true;
    if(n == 0)return target == arr[0];
    bool notTake = isTargetThere(arr,n-1,target);
    bool take = false;
    if(arr[n] <= target)
        take = isTargetThere(arr,n-1,target-arr[n]);
    return take || notTake;
}

bool isTargetThereM(int arr[],int n,int target,vector<vector<int>> &dp){
    if (target == 0)
        return true;
    if (n == 0)
        return target == arr[0];
    if(dp[n][target] != -1)return dp[n][target];
    bool notTake = isTargetThereM(arr, n - 1, target,dp);
    bool take = false;
    if (arr[n] <= target)
        take = isTargetThereM(arr, n - 1, target - arr[n],dp);
    return dp[n][target] = take || notTake;
}

bool isTargetThereT(int arr[],int n,int target){
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));

    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    if(arr[0]<=target) dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            bool notTake = dp[i-1][k];
            bool take = false;
            if(arr[i]<=k){
                take = dp[i-1][k-arr[i]];
            }
            dp[i][k] = take || notTake;
        }
    }
    return dp[n-1][target];
}

bool isTargetThereS(int arr[],int n,int target){
    vector<bool> prev(target+1,false);

    prev[0] = true;
    if(arr[0]<=target) prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        vector<bool>curr(target+1,false);
        for(int k=0;k<=target;k++){
            bool notTake = prev[k];
            bool take = false;
            if(arr[i]<=k){
                take = prev[k-arr[i]];
            }
            curr[k] = take || notTake;
        }
        prev = curr;
    }
    return prev[target];
}

int main(){
    int arr[] = {1,2,3,4};
    int target = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout<<"Is the target sum is there using brute force "<<isTargetThere(arr,n-1,target)<<endl;
    cout<<"Is the target sum is there using Memoization "<<isTargetThereM(arr,n-1,target,dp)<<endl;
    cout<<"Is the target sum is there using tabulation  "<<isTargetThereT(arr,n,target)<<endl;
    cout<<"Is the target sum is there using space opti  "<<isTargetThereS(arr,n,target)<<endl;
}