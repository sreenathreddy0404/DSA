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

int dfsTraversal(vector<vector<int>> adjList,int n){
    int count = 0;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            count++;
            dfsHelper(adjList,visited,i);
        }
    }
    cout<<endl;
    return count;
}

int main(){
    int n = 8;
    int m = 8;
    vector<vector<int>> adjList(n + 1);
    addEdge(1, 2, adjList);
    addEdge(2, 3, adjList);
    addEdge(4, 5, adjList);
    addEdge(5, 6, adjList);
    addEdge(7, 8, adjList);
    cout<<"number of provinces is "<<dfsTraversal(adjList, n);
}