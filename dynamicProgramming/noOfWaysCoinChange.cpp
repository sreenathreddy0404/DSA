#include <bits/stdc++.h>
using namespace std;

int noOfWays(int n,int arr[],int t){
    if(n == 0){
        if(t%arr[0] == 0)return 1;
        return 0;
    }
    int notPick = noOfWays(n-1,arr,t);
    int pick = 0;
    if(arr[n]<=t){
        pick = noOfWays(n,arr,t-arr[n]);
    }
    return pick+notPick;
}

int noOfWaysM(int n,int arr[],int t,vector<vector<int>> &dp){
    if(n == 0){
        if(t%arr[0] == 0)return 1;
        return 0;
    }
    if(dp[n][t] != -1)return dp[n][t];
    int notPick = noOfWaysM(n-1,arr,t,dp);
    int pick = 0;
    if(arr[n]<=t){
        pick = noOfWaysM(n,arr,t-arr[n],dp);
    }
    return dp[n][t] = pick+notPick;
}

int noOfWaysT(int n,int arr[],int t){
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    for(int i=0;i<=t;i++){
        if(i%arr[0] == 0)dp[0][i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j = 0;j<=t;j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if(arr[i]<=j){
                pick =dp[i][j-arr[i]];
            }
            dp[i][j] = pick+notPick;
        }
    }
    return dp[n-1][t];
}

int noOfWaysS(int n,int arr[],int t){
    vector<int> prev(t + 1, 0);
    for(int i=0;i<=t;i++){
        if(i%arr[0] == 0)prev[i] = 1;
    }
    for(int i=1;i<n;i++){
        vector<int> curr(t + 1, 0);
        for(int j = 0;j<=t;j++){
            int notPick = prev[j];
            int pick = 0;
            if(arr[i]<=j){
                pick = curr[j-arr[i]];
            }
            curr[j] = pick+notPick;
        }
        prev = curr;
    }
    return prev[t];
}



int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 4;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout << "number of ways to get the target using brute force " << noOfWays(n - 1, arr, target) << endl;
    cout << "number of ways to get the target using memoization " << noOfWaysM(n - 1, arr, target, dp) << endl;
    cout << "number of ways to get the target using tabulation  " << noOfWaysT(n, arr, target) << endl;
    cout << "number of ways to get the target using space opti  " << noOfWaysS(n, arr, target) << endl;
}