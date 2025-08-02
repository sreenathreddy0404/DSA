#include <bits/stdc++.h>
using namespace std;

int buysell5(vector<int> arr,int n,int buy){
    if(n >= arr.size()){
        return 0;
    }
    if(buy){
        return max(-arr[n]+buysell5(arr,n+1,0),0+buysell5(arr,n+1,1));
    }else{
        return max(arr[n]+buysell5(arr,n+2,1),0+buysell5(arr,n+1,0));
    }
}

int buysell5T(vector<int> arr){
    int size = arr.size();
    vector<vector<int>>dp(size+2,vector<int>(2,0));
    for(int n=size-1;n>=0;n--){
        for(int buy=0;buy<=1;buy++){
            if 
                (buy)dp[n][buy] =  max(-arr[n] + dp[n + 1][0], 0 + dp[n + 1][1]);
            else
                dp[n][buy] = max(arr[n] + dp[n + 2][1], 0 + dp[n + 1][0]);
        }
    }
    return dp[0][1];
}

int buysell5S(vector<int> arr){
    int size = arr.size();
    int currBuy,currNotBuy,aheadBuy,aheadNotBuy;
    aheadBuy=0;
    aheadNotBuy=0;
    for(int n=size-1;n>=0;n--){
        currNotBuy =  max(arr[n] + aheadBuy, 0 + aheadNotBuy);
        currBuy = max(-arr[n] + aheadNotBuy, 0 + aheadBuy);
        aheadBuy = currBuy;
        aheadNotBuy=currNotBuy;
    }
    return aheadBuy;
}

int main(){
    vector<int> arr = {4,9,0,4,10};
    cout<<"Using brute force : "<<buysell5(arr,0,1)<<endl;
    cout<<"Using tabulation  : "<<buysell5T(arr)<<endl;
    cout<<"space optimization : "<<buysell5S(arr)<<endl;
}