#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> arr,int ind,int lastInd){
    if(ind == arr.size()){
        return 0;
    }
    int notPick = 0+lis(arr,ind+1,lastInd);
    int pick = 0;
    if(lastInd == -1 || arr[ind]>arr[lastInd]){
        pick = 1 + lis(arr,ind+1,ind);
    }
    return max(pick,notPick);
}

int lisT(vector<int> arr){
    int len = arr.size();
    vector<vector<int>>dp(len+1,vector<int>(len+1,0));
    for(int ind=len-1;ind>=0;ind--){
        for(int lastInd = ind-1;lastInd>=-1;lastInd--){
            int notPick = 0 + dp[ind + 1][lastInd+1];
            int pick = 0;
            if (lastInd == -1 || arr[ind] > arr[lastInd]){
                pick = 1 + dp[ind + 1][ind];
            }
            dp[ind][lastInd+1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int lastInd = -1;
    cout<<"Longest increasing subsequence using bruteforce : "<<lis(arr,0,lastInd)<<endl;
    cout<<"Longest increasing subsequence using tabulation : "<<lisT(arr)<<endl;
}