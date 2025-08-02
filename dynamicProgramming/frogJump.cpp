#include<bits/stdc++.h>
using namespace std;

//bruteforce
int findMinEnergy(int arr[],int n){
    if(n == 0){
        return 0;
    }
    int cost1 = findMinEnergy(arr, n - 1) + abs(arr[n] - arr[n - 1]);
    int cost2 = INT_MAX;
    if(n>1)cost2 = findMinEnergy(arr, n - 2) + abs(arr[n] - arr[n - 2]);
    return min(cost1,cost2);
}

//memorization
int findMinEnergyM(int arr[],int n,vector<int> dp){
    if(n == 0)return 0;
    if(dp[n]!=-1) return dp[n];
    int cost1 = findMinEnergyM(arr,n-1,dp) + abs(arr[n] - arr[n-1]);
    int cost2 = INT_MAX;
    if(n>1)cost2 = findMinEnergyM(arr,n-2,dp) + abs(arr[n] - arr[n-2]);

    return dp[n] = min(cost1,cost2);
}

//tabulation
int findMinEnergyT(int arr[],int n){
    if(n == 0)return 0;
    vector<int> dp(n,0);
    for(int i=1;i<=n;i++){
        int cost1 = dp[n-1] + abs(arr[n] - arr[n-1]);
        int cost2 = INT_MAX;
        if(i>1)cost2 = dp[n-2] + abs(arr[n] - arr[n-2]);
        dp[n] = min(cost1,cost2);
    }
    return dp[n];
}



int main(){
    int arr[] = {50,60,10,60,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findMinEnergy(arr,n-1)<<endl;
    vector<int> dp(n,-1);
    cout<<findMinEnergyM(arr,n-1,dp)<<endl;
    cout<<findMinEnergyT(arr,n-1);
    return 0;
}