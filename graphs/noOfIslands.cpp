#include<bits/stdc++.h>
using namespace std;


//bfs for matrix
void connectedComponents(vector<vector<int>> map,vector<vector<bool>> &visited,int n,int m){
    queue<pair<int,int>>q;
    q.push({n,m});
    visited[n][m] = true;
    while(!q.empty()){
        pair<int,int> p = q.front();
        int currRow = p.first;
        int currCol = p.second;
        q.pop(); 
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int row = currRow+i;
                int col = currCol+j;
                if(row>=0 && col>=0 && row<map.size() && col<map[0].size()){
                    if(!visited[row][col] && map[row][col] == 1){
                        visited[row][col] = true;
                        q.push({row,col});
                    }
                }
            }
        }
    }
}

int noOfIslands(vector<vector<int>> map,int rows,int cols){
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    int count = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && map[i][j] == 1){
                cout<<i<<" , "<<j<<endl;
                count++;
                connectedComponents(map,visited,i,j);
            }
        }
    }
    return count;
}



int main(){
    vector<vector<int>> map = {
        {0,1,1,0,1},
        {0,1,1,0,1},
        {0,0,1,0,1},
        {0,0,0,0,0},
        {1,1,0,1,0},
    };
    int row = map.size();
    int col = map[0].size();
    cout<<"number of islands in map is "<<noOfIslands(map,row,col);
}