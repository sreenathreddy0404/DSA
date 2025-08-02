#include <bits/stdc++.h>
using namespace std;

//bruteforce
int maxPoints(int arr[][3],int n,int last){
    if(n == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last) maxi = max(maxi,arr[n][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int points = arr[n][i] + maxPoints(arr,n-1,i);
            maxi = max(maxi,points);
        }
    }
    return maxi;
}

//memoization
int maxPointsM(int arr[][3], int n, int last, vector<vector<int>>&dp){
    if (n == 0){
        int maxi = 0;
        for (int i = 0; i < 3; i++){
            if (i != last) maxi = max(maxi, arr[n][i]);
        }
        return maxi;
    }
    if(dp[n][last] != -1)return dp[n][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++){
        if (i != last){
            int points = arr[n][i] + maxPointsM(arr, n - 1, i,dp);
            maxi = max(maxi, points);
        }
    }
    return dp[n][last] = maxi;
}

int maxPointsT(int arr[][3], int n){
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][0],arr[0][2]);
    dp[0][2] = max(arr[0][0],arr[0][1]);
    dp[0][3] = max({arr[0][0],arr[0][1],arr[0][2]});

    for (int day = 1; day < n; day++){
        for(int last = 0; last<4; last++){
            for(int task = 0; task<3;task++){
                if (task != last){
                    int points = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], points);
                } 
            }
        }
    }
    return dp[n-1][3];
}

int maxPointsS(int arr[][3], int n){
    vector<int> dp(4,0);
    dp[0] = max(arr[0][1],arr[0][2]);
    dp[1] = max(arr[0][0],arr[0][2]);
    dp[2] = max(arr[0][0],arr[0][1]);
    dp[3] = max({arr[0][0],arr[0][1],arr[0][2]});

    for (int day = 1; day < n; day++){
        vector<int> temp(4,0);
        temp[0] = arr[day][0] + max(dp[1],dp[2]);
        temp[1] = arr[day][1] + max(dp[0],dp[2]);
        temp[2] = arr[day][2] + max(dp[0],dp[1]);
        temp[3] = max({temp[0],temp[1],temp[2]});
        dp = temp;
    }
    return dp[3];
}

int main(){
    int arr[][3] = {{10,50,1},{5,100,1},{60,50,20},{30,60,90}};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> dp(n,vector<int>(4,-1));

    cout<<"maximum merit points that ninja get using brute force "<<maxPoints(arr,n-1,3)<<endl;
    cout<<"maximum merit points that ninja get using memoization "<<maxPointsM(arr,n-1,3,dp)<<endl;
    cout<<"maximum merit points that ninja get using tabulation  "<<maxPointsT(arr,n)<<endl;
    cout<<"maximum merit points that ninja get using less space  "<<maxPointsS(arr,n)<<endl;
}