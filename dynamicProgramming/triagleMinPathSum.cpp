#include <bits/stdc++.h>
using namespace std;

// brute force
int minPathSum(vector<vector<int>> v, int m, int n){
    if (m == 0 && n == 0)
        return v[0][0];
    if (m < 0 || n < 0 || m<n)
        return 1e9;
    int up = v[m][n] + minPathSum(v, m - 1, n);
    int left = v[m][n] + minPathSum(v, m, n - 1);
    return min(up, left);
}

int findMinPathSum(vector<vector<int>> v, int m, int n){
    if(m == v.size()-1)return v[m][n];
    int down = v[m][n] + findMinPathSum(v,m+1,n);
    int right = v[m][n] + findMinPathSum(v,m+1,n+1);
    return min(down,right);
}

int findMinPathSumM(vector<vector<int>> v, int m, int n,vector<vector<int>> &dp){
    if(m == v.size()-1)return v[m][n];
    if(dp[m][n] != -1)return dp[m][n];
    int down = v[m][n] + findMinPathSumM(v,m+1,n,dp);
    int right = v[m][n] + findMinPathSumM(v,m+1,n+1,dp);
    return dp[m][n] = min(down,right);
}

int findMinPathSumT(vector<vector<int>> v, int m){
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for(int i=0;i<m;i++){
        dp[m-1][i] = v[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up = v[i][j] + dp[i+1][j];
            int left = v[i][j] + dp[i+1][j+1]; 
            dp[i][j] = min(up,left);
        }
    }
    return dp[0][0];
}

int findMinPathSumS(vector<vector<int>> v, int m){
    vector<int> dp(m,0);
    for(int i=0;i<m;i++){
        dp[i] = v[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        vector<int> temp(m,0);
        for(int j=i;j>=0;j--){
            int up = v[i][j] + dp[j];
            int left = v[i][j] + dp[j+1]; 
            temp[j] = min(up,left);
        }
        dp = temp;
    }
    return dp[0];
}



int main(){
    vector<vector<int>> v = {
        {1}, 
        {2,3}, 
        {3, 6, 7}, 
        {21, 9, 6, 10}
    };
    int m = v.size();
    vector<vector<int>> dp(m,vector<int>(m,-1));
    cout<< "minimum path sum using brute force " << findMinPathSum(v, 0, 0)<<endl;
    cout<< "minimum path sum using memoization " << findMinPathSumM(v, 0, 0,dp)<<endl;
    cout<< "minimum path sum using tabulation  " << findMinPathSumT(v, m)<<endl;
    cout<< "minimum path sum using space opti  " << findMinPathSumS(v, m)<<endl;
}