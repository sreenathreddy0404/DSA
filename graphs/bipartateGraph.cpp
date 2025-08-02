#include<bits/stdc++.h>
using namespace std;

void addEdge(int n1,int n2,vector<vector<int>> &adjList){
    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
}

bool bfs(vector<vector<int>>adjList,vector<int> &visited,int i){
    queue<int> q;
    q.push(i);
    visited[i] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjList[node]){
            if(visited[it] == -1){
                visited[it] = !visited[node];
                q.push(it);
            }else if(visited[it] == visited[node]) {
                return false;
            }
        }
    }
    return true;
}

bool bfsTraversal(vector<vector<int>>adjList,int n){
    vector<int> visited(n+1,-1);
    for(int i=1;i<=n;i++){
        if(visited[i] == -1){
            if(!bfs(adjList,visited,i)){
                return false;
            }
        }
    }
    return true;
}

bool dfs(vector<vector<int>> adjList,vector<int> &visited,int i,int pColor){
    visited[i] = pColor;
    for(auto node:adjList[i]){
        if(visited[node] == -1){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            if(!dfs(adjList,visited,node,!pColor)){
                return false;
            }
        }else if(visited[node] == pColor){
            return false;
        }
    }
    return true;
}

bool dfsTraversal(vector<vector<int>> adjList,int n){
    vector<int> visited(n+1,-1);
    for(int i=1;i<=n;i++){
        if(visited[i] == -1){
            if(!dfs(adjList,visited,i,0)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n=8;
    vector<vector<int>> adjList(n+1);
    addEdge(1,2,adjList);
    addEdge(2,3,adjList);
    addEdge(3,4,adjList);
    addEdge(4,5,adjList);
    addEdge(5,6,adjList);
    addEdge(6,7,adjList);
    addEdge(4,8,adjList);
    addEdge(7,2,adjList);
    
    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(auto it:adjList[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    if(bfsTraversal(adjList,n)){
        cout<<"It is a bipartate graph";
    }else{
        cout<<"Not a bipartate graph";
    }
    cout<<endl;
    if(dfsTraversal(adjList,n)){
        cout<<"It is a bipartate graph";
    }else{
        cout<<"Not a bipartate graph";
    }
}