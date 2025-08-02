#include<bits/stdc++.h>
using namespace std;

int rowDir[] = {-1,0,1,0};
int colDir[] = {0,1,0,-1};

vector<pair<int,int>> countIslands(vector<vector<int>> map,vector<vector<bool>> &visited,int i,int j){
    int rows = map.size();
    int cols = map[0].size();
    queue<pair<int,int>> q;
    vector<pair<int, int>> island;
    q.push({i, j});
    visited[i][j] = true;
    island.push_back({0,0});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int n=0;n<4;n++){
            int nrow = row+rowDir[n];
            int ncol = col+colDir[n];
            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols){
                if(!visited[nrow][ncol] && map[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true;
                    island.push_back({nrow-i,ncol-j});
                }
            }
        }
    }
    return island;
}

int countDistinctIslands(vector<vector<int>> map,int rows,int cols){
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    set<vector<pair<int,int>>> s;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && map[i][j] == 1){
                vector<pair<int,int>> island = countIslands(map,visited,i,j);
                s.insert(island);
            }
        }
    }
    for(auto it:s){
        for(auto it1:it){
            cout<<"{"<<it1.first<<","<<it1.second<<"} ";
        }
        cout<<endl;
    }
    return s.size();
}



int main(){
    vector<vector<int>> map = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,1,1},
        {1,1,0,1,0},
    };
    int rows = map.size();
    int cols = map[0].size();
    cout<<"No of distinct islands is "<<countDistinctIslands(map,rows,cols);
}