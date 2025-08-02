#include<bits/stdc++.h>
using namespace std;

int rowDir[] = {-1,0,1,0};
int colDir[] = {0,1,0,-1};


void findDistance(vector<vector<int>> map,vector<vector<int>> &distanceArray,int rows,int cols){
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(map[i][j] == 1){
                visited[i][j] = true;
                q.push({{i,j},0});
            }
        }
    }
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = row+rowDir[i];
            int ncol = col+colDir[i];
            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols){
                if(!visited[nrow][ncol] && map[nrow][ncol] == 0){
                    q.push({{nrow,ncol},dis+1});
                    visited[nrow][ncol] = true;
                    distanceArray[nrow][ncol] = dis+1;
                }
            }
        }
    }
}



int main(){
    vector<vector<int>> map = {
        {0,1,1,0,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {1,1,0,0,0},
    };
    int rows = map.size();
    int cols = map[0].size();
    vector<vector<int>> distanceArray(rows,vector<int>(cols,0));
    findDistance(map,distanceArray,rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<distanceArray[i][j]<<" ";
        }
        cout<<endl;
    }
}