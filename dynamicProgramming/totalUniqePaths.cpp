#include <bits/stdc++.h>
using namespace std;

//bruteforce
int uniquePaths(int i,int j){
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;
    int up = uniquePaths(i-1,j);
    int left = uniquePaths(i,j-1);
    return up+left;
}

//memoization
int uniquePathsM(int i,int j,vector<vector<int>> &dp){
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up = uniquePaths(i - 1, j);
    int left = uniquePaths(i, j - 1);
    return dp[i][j] = up + left;
}

//tabulation
int uniquePathsT(int m,int n){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0)continue;
            if(i>0)dp[i][j] += dp[i-1][j];
            if(j>0)dp[i][j] += dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

//space Optimization
int uniquePathsS(int m,int n){
    vector<int> dp(n,0);
    for(int i = 0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(j == 0)temp[j] = 1;
            else temp[j] = dp[j]+temp[j-1];
        }
        dp = temp;
    }
    return dp[n-1];
}


int main(){
    int arr[7][3];
    int i = sizeof(arr)/sizeof(arr[0]);
    int j = sizeof(arr[0])/sizeof(arr[0][0]);
    cout<<"Total unique paths in a grid using brute force "<<uniquePaths(i-1,j-1)<<endl;
    vector<vector<int>> dp(i,vector<int>(j,-1));
    cout<<"Total unique paths in a grid using memoization "<<uniquePathsM(i-1,j-1,dp)<<endl;
    cout<<"Total unique paths in a grid using tabulation  "<<uniquePathsT(i,j)<<endl;
    cout<<"Total unique paths in a grid using tabulation but space optimized  "<<uniquePathsS(i,j)<<endl;
}