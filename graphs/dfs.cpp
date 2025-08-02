#include<bits/stdc++.h>
using namespace std;

void addEdge(int n1,int n2,vector<vector<int>> &adjList){
    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
}

void dfsHelper(vector<vector<int>> adjList,vector<bool> &visited,int i){
    visited[i] = true;
    cout<<i<<" ";
    for(auto it:adjList[i]){
        if(!visited[it]){
            dfsHelper(adjList,visited,it);
        }
    }
}

void dfsTraversal(vector<vector<int>> adjList,int n){
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfsHelper(adjList,visited,i);
        }
    }
}


void dfs(vector<vector<int>> adjList,vector<bool> &visited,int i){
    visited[i] = true;
    cout<<i<<" ";
    for(auto it:adjList[i]){
        if(!visited[it]){
            dfs(adjList,visited,it);
        }
    }
}

int main(){
    int n = 8;
    int m = 8;
    vector<vector<int>> adjList(n + 1);
    addEdge(1, 2, adjList);
    addEdge(1, 6, adjList);
    addEdge(2, 3, adjList);
    addEdge(2, 4, adjList);
    addEdge(6, 7, adjList);
    addEdge(6, 8, adjList);
    addEdge(4, 5, adjList);
    addEdge(5, 7, adjList);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" -> ";
    //     for(auto it:adjList[i]){
    //         cout<<it<<",";
    //     }
    //     cout<<endl;
    // }
    dfsTraversal(adjList, n);
}