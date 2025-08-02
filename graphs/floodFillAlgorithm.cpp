#include<bits/stdc++.h>
using namespace std;

vector<int> rowDir = {-1,0,1,0};
vector<int> colDir = {0,1,0,-1};

void floodFill(vector<vector<int>> &image,int sr,int sc,int newColor){
    int initialColor = image[sr][sc];
    int rows = image.size();
    int cols = image[0].size();
    queue<pair<int,int>> q;
    q.push({sr,sc});
    image[sr][sc] = newColor;
    while(!q.empty()){
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newRow = currRow+rowDir[i];
            int newCol = currCol+colDir[i];
            if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
                if(image[newRow][newCol] == initialColor){
                    q.push({newRow,newCol});
                    image[newRow][newCol] = newColor;
                }
            }
        }
    }
}

void floodFillDfs(vector<vector<int>> &image,int currRow,int currCol,int newColor,int initColor){
    int rows = image.size();
    int cols = image[0].size();

    for(int i=0;i<4;i++){
        int newRow = currRow+rowDir[i];
        int newCol = currCol+colDir[i];
        if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
            if(image[newRow][newCol] == initColor){
                image[newRow][newCol] = newColor;
                floodFillDfs(image,newRow,newCol,newColor,initColor);
            }
        }
    }
}


//you can move only four directions top bottom left right, you are give starting row and column
//and also a newcolor and you can go throught any direction and make the fill with newcolor .
//you can move only if the pixel is connected.
int main(){
    vector<vector<int>> image = {
        {0,2,2,0,2},
        {0,2,2,2,2},
        {0,0,2,0,1},
        {0,3,0,4,0},
        {2,1,0,1,0},
    };
    int sr = 1;
    int sc = 1;
    int newColor = 3;
    int initColor = image[sr][sc];
    floodFillDfs(image,sr,sc,newColor,initColor);

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}