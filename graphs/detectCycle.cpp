#include<bits/stdc++.h>
using namespace std;

void addEdge(int n1,int n2,vector<vector<int>> &adjList){
    adjList[n1].push_back(n2);
    adjList[n2].push_back(n1);
}

bool bfsHelper(vector<vector<int>> adjList,vector<bool> &visited,int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        int count = 0;
        for(auto it : adjList[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }else{
                count++;
            }
        }
        if(count>1){
            return true;
        }
    }
    return false;
}


bool bfs(vector<vector<int>>adjList,vector<bool> &visited,int i){
    queue<pair<int,int>> q;
    q.push({i,-1});
    visited[i] = true;
    while(!q.empty()){
        int n = q.front().first;
        int parent = q.front().second;
        q.pop();
        // cout<<n<<" ";
        for(auto it:adjList[n]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it,n});
            }else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}

bool bfsTraversal(vector<vector<int>>adjList,int n){
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(!bfs(adjList,visited,i)){
                return false;
            }
        }
    }
    return true;
}

bool dfs(vector<vector<int>> adjList,vector<bool> &visited,int i,int parent){
    visited[i] = true;
    for(auto node:adjList[i]){
        if(!visited[node]){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            dfs(adjList,visited,node,i);
        }else if(node != parent){
            return true;
        }
    }
    return false;
}

bool dfsTraversal(vector<vector<int>> adjList,int n){
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(adjList,visited,i,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n=5;
    vector<vector<int>> adjList(n+1);
    addEdge(1,2,adjList);
    addEdge(2,3,adjList);
    addEdge(2,5,adjList);
    addEdge(3,4,adjList);
    // addEdge(4,5,adjList);
    // addEdge(4,5,adjList);
    // addEdge(6,7,adjList);
    
    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(auto it:adjList[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    if(bfsTraversal(adjList,n)){
        cout<<"Cycle is detected";
    }else{
        cout<<"No cycle detected";
    }
    cout<<endl;
    if(dfsTraversal(adjList,n)){
        cout<<"Cycle is detected";
    }else{
        cout<<"No cycle detected";
    }
}