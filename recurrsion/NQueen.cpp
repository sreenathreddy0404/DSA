#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int n, int col,int row){
    int tempRow = row;
    int tempCol = col;

    //upper diagonal;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')return false;
        row--;
        col--;
    }

    row = tempRow;
    col = tempCol;

    //left side of col;
    while(col>=0){
        if(board[row][col] == 'Q')return false;
        col--;
    }

    row = tempRow;
    col = tempCol;

    //lower diagonal;
    while(row<n && col>=0){
        if(board[row][col] == 'Q')return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col,vector<vector<char>> &board, vector<vector<vector<char>>> &ans,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(board,n,col,row)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '-';
        }
    }
}

vector<vector<vector<char>>> nqueens(int n){
    vector<vector<vector<char>>> ans;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    solve(0,board,ans,n);
    // ans.push_back(board);
    return ans;
}

int main(){
    int n = 5;
    vector<vector<vector<char>>> ans_boards = nqueens(n);

    int size = ans_boards.size();

    for(int i=0;i<size;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<ans_boards[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}