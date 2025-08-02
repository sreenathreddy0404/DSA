#include <bits/stdc++.h>
using namespace std;

void addEdge(int n1, int n2, vector<vector<int>> &adjList)
{
    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
}

void bfs(vector<vector<int>> adjList,vector<bool> &visited,int n){
    queue<int> q;
    visited[n] = true;
    q.push(n);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adjList[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

void bfsTraversal(vector<vector<int>> adjList,int n){
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(adjList,visited,i);
        }
    }
}

void dfs(vector<vector<int>> adjList,vector<bool> &visited,int n){
    visited[n] = true;
    cout<<n<<" ";
    for(auto node:adjList[n]){
        if(!visited[node]){
            dfs(adjList,visited,node);
        }
    }
}

void dfsTraversal(vector<vector<int>> adjList,int n){
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adjList,visited,i);
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
    bfsTraversal(adjList, n);
    cout<<endl;
    dfsTraversal(adjList,n);
}