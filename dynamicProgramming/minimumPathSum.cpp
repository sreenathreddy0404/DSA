#include <bits/stdc++.h>
using namespace std;

int findMinSum(int arr[][4],int m,int n){
    if(m == 0 && n == 0)return arr[m][n];
    if(m<0 || n<0) return 1e9;

    int up = arr[m][n] + findMinSum(arr,m-1,n);
    int left = arr[m][n] + findMinSum(arr,m,n-1);
    return min(up,left);
}

int findMinSumM(int arr[][4],int m,int n,vector<vector<int>> &dp){
    if(m == 0 && n == 0)return arr[m][n];
    if(m<0 || n<0) return 1e9;
    if(dp[m][n]!=-1)return dp[m][n];

    int up = arr[m][n] + findMinSumM(arr,m-1,n,dp);
    int left = arr[m][n] + findMinSumM(arr,m,n-1,dp);
    return dp[m][n] = min(up,left);
}

int findMinSumT(int arr[][4],int m,int n){

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = arr[0][0];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int up = 1e9;
            int left = 1e9;
            if(i == 0 && j == 0)continue;
            if(i>0)up = arr[i][j] + dp[i-1][j];
            if(j>0)left = arr[i][j] + dp[i][j-1];
            dp[i][j] = min(up,left);
        }
    }
    return dp[m-1][n-1];
}

int findMinSumS(int arr[][4],int m,int n){

    vector<int> dp(n, 0);

    for(int i=0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0)temp[j] = arr[0][0];
            else if(i == 0) temp[j] = arr[i][j] + temp[j - 1];
            else if(j == 0) temp[j] = arr[i][j] + dp[j];
            else temp[j] = arr[i][j]+min(temp[j-1],dp[j]);
        }
        dp = temp;
    }
    return dp[n-1];
}



int main(){
    int arr[][4] = {{5,9,6,5},{11,5,2,2},{1,9,2,1}};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr[0])/sizeof(arr[0][0]);
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<"minimum sum using brute force "<<findMinSum(arr,m-1,n-1)<<endl;
    cout<<"minumum sum using memoization "<<findMinSumM(arr,m-1,n-1,dp)<<endl;
    cout<<"minumum sum using tabulation  "<<findMinSumT(arr,m,n)<<endl;
    cout<<"minumum sum using tabulation but so  "<<findMinSumS(arr,m,n)<<endl;
}