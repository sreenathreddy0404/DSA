#include<bits/stdc++.h>
using namespace std;

vector<int> rowDir = {-1,0,1,0};
vector<int> colDir = {0,1,0,-1};

void minTimeHelper(vector<vector<int>> bucket,vector<vector<int>> &timeArray,int i,int j){
    int rows = bucket.size();
    int cols = bucket[0].size();
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{i,j},0});
    visited[i][j] = true;
    while(!q.empty()){
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int minTime = q.front().second;
        q.pop();
        for(int n=0;n<4;n++){
            int newRow = currRow+rowDir[n];
            int newCol = currCol+colDir[n];
            if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
                if(!visited[newRow][newCol] && bucket[newRow][newCol] == 1){
                    q.push({{newRow,newCol},minTime+1});
                    if(timeArray[newRow][newCol] == -1)timeArray[newRow][newCol] = minTime+1;
                    else timeArray[newRow][newCol] = min(minTime+1,timeArray[newRow][newCol]);
                    visited[newRow][newCol] = true;
                }
            }
        } 
    }
}


int minTime(vector<vector<int>> bucket){
    int rows = bucket.size();
    int cols = bucket[0].size();
    vector<vector<int>> timeArray(rows,vector<int>(cols,-1));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(bucket[i][j] == 2){
                minTimeHelper(bucket,timeArray,i,j);
            }
        }
    }
    int maxTime = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // cout<<timeArray[i][j]<<"\t";
            maxTime = max(maxTime,timeArray[i][j]);
        }
        // cout<<endl;
    }
    return maxTime;
}

//efficient
int rottenOranges(vector<vector<int>> bucket){
    int rows = bucket.size();
    int cols = bucket[0].size();

    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(bucket[i][j] == 2){
                q.push({{i,j},0});
            }
        }
    }

    vector<vector<int>>timeArray(rows,vector<int>(cols,0));

    while(!q.empty()){
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int time = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newRow = currRow+rowDir[i];
            int newCol = currCol+colDir[i];
            if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && bucket[newRow][newCol] == 1){
                q.push({{newRow,newCol},time+1});
                timeArray[newRow][newCol] = time+1;
                bucket[newRow][newCol] = 2;
            }
        }
    }

    int maxTime = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<timeArray[i][j]<<"\t";
            maxTime = max(maxTime,timeArray[i][j]);
        }
        cout<<endl;
    }
    return maxTime;
}


//1 -> fresh orange
//2 -> rotten orange
//0 -> no orange
//a rotten orange can rotten only in four directions.
//a rotten orange can rotten it's neighbour orange in unit time
//minimum time taken to rotten all the neighbour oranges.
int main(){
    vector<vector<int>> bucket = {
        {0,1,2,0,1},
        {0,1,0,1,1},
        {0,1,1,1,1},
        {0,1,0,1,0},
        {2,1,0,1,0},
    };
    cout<<"minimum time to take all oranges rotten is "<<minTime(bucket)<<endl;
    cout<<"minimum time to take all oranges rotten is "<<rottenOranges(bucket);
}