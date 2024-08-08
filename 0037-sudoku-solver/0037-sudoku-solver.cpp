class Solution {
public:

    bool IsSafe(vector<vector<char>>& board,int row,int col,char digit){
        for(int k=0;k<9;k++){
            if(board[row][k] == digit) return false;
        }
        for(int k=0;k<9;k++){
            if(board[k][col] == digit) return false;
        }
        for(int k=0;k<9;k++){
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit) return false;
        }
        return true;

    }

    bool solve(vector<vector<char>>& board){

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(char digit = '1';digit<='9';digit++){
                        if(IsSafe(board,i,j,digit)==true){
                        
                            board[i][j] = digit;
                            bool solveHoRhaHai = solve(board);
                            if(solveHoRhaHai == true){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);

    }
};