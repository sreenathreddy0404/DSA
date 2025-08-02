#include <bits/stdc++.h>
using namespace std;

int minCoins(int n,int arr[],int target){
    // if(target == 0)return 0;
    if(n == 0){
        if(target%arr[0] == 0)return target/arr[0];
        else return 1e9;
    }

    int notPick = 0 + minCoins(n-1,arr,target);
    int pick = INT_MAX;
    if(arr[n]<=target){
        pick = 1 + minCoins(n,arr,target-arr[n]);
    }
    return min(pick,notPick);
}

int minCoinsM(int n,int arr[],int target,vector<vector<int>> &dp){
    // if(target == 0)return 0;
    if(n == 0){
        if(target%arr[0] == 0)return target/arr[0];
        else return 1e9;
    }

    if(dp[n][target] != -1)return dp[n][target];
    int notPick = 0 + minCoinsM(n-1,arr,target,dp);
    int pick = INT_MAX;
    if(arr[n]<=target){
        pick = 1 + minCoinsM(n,arr,target-arr[n],dp);
    }
    return dp[n][target] =  min(pick,notPick);
}

int minCoinsT(int n,int arr[],int target){
    vector<vector<int>> dp(n,vector<int>(target+1,1e9));
    for(int i=0;i<=target;i++){
        if(i%arr[0] == 0)dp[0][i] = i/arr[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int notPick = 0 + dp[i-1][j];
            int pick = 1e9;
            if(arr[i]<=j){
                pick = 1 + dp[i][j-arr[i]];
            }
            dp[i][j] = min(pick,notPick);
        }
    }
    
    return (dp[n-1][target] >= 1e9)?-1:dp[n-1][target];
}

int minCoinsS(int n,int arr[],int target){
    vector<int> prev(target+1,1e9);
    for(int i=1;i<target;i++){
        if(i%arr[0] == 0)prev[i] = i/arr[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(target + 1, 1e9);
        for(int j=1;j<=target;j++){
            int notPick = 0 + prev[j];
            int pick = INT_MAX;
            if(arr[i]<=j){
                pick = 1 + curr[j-arr[i]];
            }
            curr[j] = min(pick,notPick);
        }
        prev = curr;
    }
    
    return prev[target];
}



int main(){
    int arr[] = {9,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 11;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout<<"minimum coins required is using brute force "<<minCoins(n-1,arr,target)<<endl;
    cout<<"minimum coins required is using memoization "<<minCoinsM(n-1,arr,target,dp)<<endl;
    cout<<"minimum coins required is using tabulation  "<<minCoinsT(n,arr,target)<<endl;
    cout<<"minimum coins required is using space opti  "<<minCoinsS(n,arr,target)<<endl;
}