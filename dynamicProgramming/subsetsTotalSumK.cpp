#include <bits/stdc++.h>
using namespace std;


//TC = O(2^N) SC=O(N)
int countSubsetsWithSumK(int arr[],int n,int sum){
    if(sum == 0)return 1;
    if(n == 0){
        if(sum == arr[0]) return 1;
        return 0;
    }

    int notTake = countSubsetsWithSumK(arr,n-1,sum);
    int take = 0;
    if(arr[n] <= sum){
        take = countSubsetsWithSumK(arr,n-1,sum-arr[n]);
    }
    return take+notTake;
}

//TC = O(n * sum) SC= O(n*m  + N)
int countSubsetsWithSumKM(int arr[],int n,int sum,vector<vector<int>> &dp){
    if(sum == 0)return 1;
    if(n == 0){
        if(sum == arr[0]) return 1;
        return 0;
    }

    if(dp[n][sum] != -1)return dp[n][sum];

    int notTake = countSubsetsWithSumKM(arr,n-1,sum,dp);
    int take = 0;
    if(arr[n] <= sum){
        take = countSubsetsWithSumKM(arr,n-1,sum-arr[n],dp);
    }
    return dp[n][sum] = take+notTake;
}

//TC = O(N*SUM) SC= O(N*SUM)
int countSubsetsWithSumKT(int arr[],int n,int sum){
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(sum>=arr[0])dp[0][arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        for(int k=1;k<=sum;k++){
            int notTake = dp[i-1][sum];
            int take = 0;
            if(arr[i] <= sum){
                take = dp[i-1][sum-arr[i]];
            }
            dp[i][k] = take+notTake;
        }
    }
    return dp[n-1][sum];
}


//TC = O(N*SUM) SC= O(N*SUM)
int countSubsetsWithSumKS(int arr[],int n,int sum){
    vector<int> prev(sum + 1, 0);

    prev[0] = 1;
    if(sum>=arr[0])prev[arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        vector<int> curr(sum + 1, 0);
        for(int k=1;k<=sum;k++){
            int notTake = prev[sum];
            int take = 0;
            if(arr[i] <= sum){
                take = prev[sum-arr[i]];
            }
            curr[k] = take+notTake;
        }
        prev = curr;
    }
    return prev[sum];
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 9, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 9;

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<"Count no of subset with sum "<<sum<<" is using brute force "<<countSubsetsWithSumK(arr,n-1,sum)<<endl;
    cout<<"Count no of subset with sum "<<sum<<" is using memoization "<<countSubsetsWithSumKM(arr,n-1,sum,dp)<<endl;
    cout<<"Count no of subset with sum "<<sum<<" is using tabulation  "<<countSubsetsWithSumKT(arr,n,sum)<<endl;
    cout<<"Count no of subset with sum "<<sum<<" is using space Opti  "<<countSubsetsWithSumKT(arr,n,sum)<<endl;
}