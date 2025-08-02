#include <bits/stdc++.h>
using namespace std;

void printNonAdjacentElements(int arr[],int n,int ind,vector<int> temp){
    if(ind>=n){
        for(auto ele:temp){
            cout<<ele<<" ";
        }
        cout<<endl;
        return;
    }

    temp.push_back(arr[ind]);
    printNonAdjacentElements(arr,n,ind+2,temp);
    temp.pop_back();
    printNonAdjacentElements(arr,n,ind+1,temp);
}

int printMaxSumOfNonAdjElements(int arr[],int n,int ind){
    if(ind == n-1)return arr[n-1]; 
    if(ind>=n){
        return 0;
    }
    int pickSum = arr[ind] + printMaxSumOfNonAdjElements(arr,n,ind+2);
    int notPickSum = 0 + printMaxSumOfNonAdjElements(arr,n,ind+1);
    return max(pickSum,notPickSum);
}

int printMaxSumOfNonAdjElementsM(int arr[], int n,vector<int> &dp){
    if (n == 0) return arr[0];
    if (n < 0) return 0;
    if(dp[n]!=-1){
        // cout << "hit at index " << n << endl;
        return dp[n];
    }
    int pickSum = arr[n] + printMaxSumOfNonAdjElementsM(arr, n-2,dp);
    int notPickSum = 0 + printMaxSumOfNonAdjElementsM(arr, n-1,dp);
    return dp[n] = max(pickSum, notPickSum);
}

int printMaxSumOfNonAdjElementsT(int arr[],int n){
    vector<int> dp(n+1,-1);
    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        int take = arr[i];
        if(i>1)take +=  dp[i-2];
        int nottake = 0 + dp[i-1];

        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

int printMaxSumOfNonAdjElementsS(int arr[], int n){
    int prev1 = arr[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++){
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int nottake = 0 + prev1; 
        prev2 = prev1;
        prev1 = max(take, nottake);
    }
    return prev1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> temp;
    // printNonAdjacentElements(arr,n,0,temp);

    cout<<"Max sum of adjacent elements using brutforce is "<<printMaxSumOfNonAdjElements(arr,n,0)<<endl;

    vector<int> dp(n+1,-1);
    cout<<"Max sum of adjacent elements using memoization is "<<printMaxSumOfNonAdjElementsM(arr,n-1,dp)<<endl;
    for(auto ele:dp){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"Max sum of adjacent elements using Tabulation is " << printMaxSumOfNonAdjElementsT(arr, n) << endl;
    cout<<"Max sum of adjacent elements using Tabulation but space optimization is " << printMaxSumOfNonAdjElementsS(arr, n) << endl;
}