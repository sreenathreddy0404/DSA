#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board,int row,int col, char num){
    //row;
    for(int i=0;i<9;i++){
        if(board[row][i] == num)return false;
    }

    //col
    for(int i=0;i<9;i++){
        if(board[i][col] == num)return false;
    }

    //box
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[boxRow+i][boxCol+j] == num)return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col] == '-'){
                for(char i='1';i<='9';i++){
                    if(isSafe(board,row,col,i)){
                        board[row][col] = i;
                        if(solve(board)) return true;
                        board[row][col] = '-';
                    }
                }
                return false;
            }
        } 
    }
    return true;
}

vector<vector<char>> sudokoSolver(vector<vector<char>> board){      
    solve(board);
    return board;
}

int main(){
    vector<vector<char>> board = {
        {'9','8','4','-','-','-','6','7','-'},
        {'6','1','-','8','-','-','5','-','-'},
        {'-','5','7','-','-','-','-','3','1'},
        {'-','7','1','9','-','-','4','-','-'},
        {'4','2','-','1','8','-','7','-','3'},
        {'5','-','-','3','-','4','-','-','-'},
        {'7','-','5','2','-','-','-','-','-'},
        {'-','-','2','4','9','-','-','5','7'},
        {'1','9','-','-','-','3','2','-','-'}
    };
    vector<vector<char>> ans_board =  sudokoSolver(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<ans_board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}