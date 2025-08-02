#include <bits/stdc++.h>
using namespace std;


int maxChocolates(vector<vector<int>> v,int m,int n,int i,int j1,int j2){
    if (j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
        return -1e9;
    if(i == m-1){
        if(j1 == j2) return v[i][j1];
        else return v[i][j1]+v[i][j2];
    }

    int maxi = -1e9;
    for(int p = -1; p<=1; p++){
        for(int q = -1; q<=1; q++){
            int value = 0;
            if(j1 == j2) value = v[i][j1];
            else value = v[i][j1] + v[i][j2];

            value += maxChocolates(v,m,n,i+1,j1+p,j2+q);
            maxi = max(maxi,value);
        }
    }

    return maxi;
}

int maxChocolatesM(vector<vector<int>> v, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
    if (j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
        return -1e9;
    if(i == m-1){
        if(j1 == j2) return v[i][j1];
        else return v[i][j1]+v[i][j2];
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }

    int maxi = -1e9;
    for(int p = -1; p<=1; p++){
        for(int q = -1; q<=1; q++){
            int value = 0;
            if(j1 == j2) value = v[i][j1];
            else value = v[i][j1] + v[i][j2];

            value += maxChocolatesM(v,m,n,i+1,j1+p,j2+q,dp);
            maxi = max(maxi,value);
        }
    }

    return dp[i][j1][j2] =  maxi;
}

int maxChocolatesT(vector<vector<int>> v, int m, int n){
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2){
                dp[m-1][j1][j2] = v[m-1][j1];
            }else{
                dp[m-1][j1][j2] = v[m-1][j1] + v[m-1][j2];
            }
        }
    }

    for(int i = m-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e9;
                for (int p = -1; p <= 1; p++){
                    for (int q = -1; q <= 1; q++){
                        int value = 0;
                        if (j1 == j2)value = v[i][j1];
                        else value = v[i][j1] + v[i][j2];
                        if (j1 + p >= 0 && j1 + p < m && j2 + q >= 0 && j2 + q < m)
                            value += dp[i + 1][j1 + p][j2 + q];
                        else value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1];
}


int main(){
    vector<vector<int>> v = {
        {10,2,8},
        {6,9,11},
        {4,2,6}
    };
    int m = v.size();
    int n = v[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    cout<<"maximum chocolates using brute force "<<maxChocolates(v,m,n,0,0,n-1)<<endl;
    cout<<"maximum chocolates using Memoization "<<maxChocolatesM(v,m,n,0,0,n-1,dp)<<endl;
    cout<<"maximum chocolates using tabulation  "<<maxChocolatesT(v,m,n)<<endl;
}