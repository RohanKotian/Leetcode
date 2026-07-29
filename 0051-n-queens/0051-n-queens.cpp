class Solution {
public:
    bool isSafe(int i, int j, int n, vector<string>& board){        
        for(int k=0; k<j; k++){
            if(board[i][k]=='Q') return false;
        }
        int ci = i, cj = j;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--, j--;
        }
        
        i = ci, j = cj;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++, j--;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& res){
        if(col>=n){
            res.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solve(col+1, n, board, res);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        solve(0, n, board, res);
        return res;
    }
};