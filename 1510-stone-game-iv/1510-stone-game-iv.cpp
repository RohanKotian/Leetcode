class Solution {
public:
    bool solve(int n, vector<int>& squares, vector<int>& dp){
        if(n==0){
            return false;
        }

        if(dp[n] != -1) return dp[n];

        for(int sq:squares){
            if(sq > n) break;
            if(!solve(n-sq, squares, dp)){
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp (n+1, -1);
        vector<int> squares;

        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
        }

        return solve(n, squares, dp);
    }
};