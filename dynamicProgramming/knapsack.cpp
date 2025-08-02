#include <bits/stdc++.h>
using namespace std;

int maxValue(int n,vector<int> weights,vector<int> values,int weight){
    if(n == 0){
        if(weight>=weights[0]){
            return values[0];
        }else{
            return 0;
        }
    }

    int notSteal = 0 + maxValue(n-1,weights,values,weight);
    int steal = INT_MIN;
    if(weights[n] <= weight){
        steal = values[n] + maxValue(n-1,weights,values,weight-weights[n]);
    }
    return max(steal,notSteal);
}

int maxValueM(int n,vector<int> weights,vector<int> values,int weight,vector<vector<int>> &dp){
    if(n == 0){
        if(weight>=weights[0]){
            return values[0];
        }else{
            return 0;
        }
    }

    if(dp[n][weight] != -1)return dp[n][weight];
    int notSteal = 0 + maxValueM(n-1,weights,values,weight,dp);
    int steal = INT_MIN;
    if(weights[n] <= weight){
        steal = values[n] + maxValueM(n-1,weights,values,weight-weights[n],dp);
    }
    return dp[n][weight] = max(steal, notSteal);
}

int maxValueT(int n,vector<int> weights,vector<int> values,int weight){
    vector<vector<int>> dp(n,vector<int>(weight+1,0));
    for(int w=0;w<=weight;w++){
        if(w>=weights[0]) dp[0][w] = values[0];
    }

    
    for(int i=1;i<n;i++){
        for(int w=0;w<=weight;w++){
            int notSteal = 0 + dp[i-1][w];
            int steal = 0;
            if(weights[i] <= w){
                steal = values[i] + dp[i-1][w-weights[i]];
            }
            
            dp[i][w] = max(steal,notSteal);
        }
    }
    // cout<<endl;
    for(int i=0;i<n;i++){
        for(int w=0;w<=weight;w++){
            cout<<dp[i][w]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[n-1][weight];
}

int maxValueS1(int n,vector<int> weights,vector<int> values,int weight){
    vector<int> prev(weight + 1, 0);
    for(int w=0;w<weight;w++){
        if(w>=weights[0]) prev[w] = values[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(weight+1,0);
        for(int w=0;w<=weight;w++){
            int notSteal = 0 + prev[w];
            int steal = 0;
            if(weights[i] <= w){
                steal = values[i] + prev[w-weights[i]];
            }
            curr[w] = max(steal,notSteal);
        }
        prev = curr;
    }
    return prev[weight];
}

int maxValueS2(int n,vector<int> weights,vector<int> values,int weight){
    vector<int> curr(weight + 1, 0);
    for(int w=0;w<weight;w++){
        if(w>=weights[0]) curr[w] = values[0];
    }

    for(int i=1;i<n;i++){
        for(int w=weight;w>=0;w--){
            int notSteal = 0 + curr[w];
            int steal = 0;
            if(weights[i] <= w){
                steal = values[i] + curr[w-weights[i]];
            }
            curr[w] = max(steal,notSteal);
        }
    }
    return curr[weight];
}



int main(){
    vector<int> weights = {3,2,7,5};
    vector<int> values = {30,40,30,80};
    int n=weights.size();
    int weight = 5;
    vector<vector<int>> dp(n, vector<int>(weight + 1, -1));
    cout<<"find the maximum value that theif get using brute force "<<maxValue(n-1,weights,values,weight)<<endl;
    cout<<"find the maximum value that theif get using memoization "<<maxValueM(n-1,weights,values,weight,dp)<<endl;
    cout<<"find the maximum value that theif get using tabulation  "<<maxValueT(n,weights,values,weight)<<endl;
    cout<<"find the maximum value that theif get using space opti1 "<<maxValueS1(n,weights,values,weight)<<endl;
    cout<<"find the maximum value that theif get using space opti2 "<<maxValueS2(n,weights,values,weight)<<endl;
}