#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adjList,int n1,int n2){
    adjList[n1].push_back(n2);
}

bool cycleDetected(vector<vector<int>> adjList,vector<bool> &visited, vector<bool> &pathVisited,int n){
    visited[n] = true;
    pathVisited[n] = true;
    for(auto node:adjList[n]){
        if(!visited[node]){
            if(cycleDetected(adjList,visited,pathVisited,node)) return true;
            pathVisited[node] = false;
        }else if(pathVisited[node]){
            return true;
        }
    }
    return false;
}


bool printSafeNode(vector<vector<int>> adjList,int n){
    vector<bool> visited(n+1,false);
    vector<bool> pathVisited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(cycleDetected(adjList,visited,pathVisited,i))return true;
        }
    }
    return false;
}

int main(){
    int n=5;
    vector<vector<int>> adjList(n+1);
    addEdge(adjList,1,2);
    addEdge(adjList,2,3);
    addEdge(adjList,1,4);
    addEdge(adjList,4,5);
    addEdge(adjList,3,5);
    // addEdge(adjList,6,7);
    // addEdge(adjList,4,7);

    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(auto it:adjList[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }

    //safe node is a node where no cycle exists for the given node.
    cout<<printSafeNode(adjList,n);
}