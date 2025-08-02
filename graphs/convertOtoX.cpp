//convert O's to X which are surrounded by X's if not leave as it is;
#include<bits/stdc++.h>
using namespace std;

int rowDir[] = {-1,0,1,0};
int colDir[] = {0,1,0,-1};


void convert(vector<vector<char>> &map,int rows,int cols){
    queue<pair<int,int>>q;
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==0 || i==rows-1 || j==0 || j==cols-1){
                if(map[i][j] == 'O'){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
            
        }
    }
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = row+rowDir[i];
            int ncol = col+colDir[i];
            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols){
                if(!visited[nrow][ncol] && map[nrow][ncol] == 'O'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && map[i][j] == 'O'){
                map[i][j] = 'X';
            }
        }
    }
}



int main(){
    vector<vector<char>> map = {
        {'X','O','O','X','X'},
        {'O','O','X','O','X'},
        {'X','O','X','O','X'},
        {'X','O','X','O','X'},
        {'X','X','X','X','X'},
    };
    int rows = map.size();
    int cols = map[0].size();
    convert(map,rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}