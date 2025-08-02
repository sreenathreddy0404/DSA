    for(char i='1';i<='9';i++){
                    if(isSafe(board,row,col,i)){
                        board[row][col] = i;
                        if(solve(board)) return true;
                        else board[row][col] = '-';
                    }
                }
                return false;