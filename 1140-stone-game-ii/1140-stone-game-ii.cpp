class Solution {
public:
    int n;
    int solve(int ind, int M, vector<int>& piles, vector<int>& suffix, vector<vector<int>>& dp){
        if(ind>=n){
            return 0;
        }

        if(dp[ind][M] != -1) return dp[ind][M];
        
        int res = -1;
        for(int x=1; x<=min(n-ind, 2*M); x++){
            res = max(res, suffix[ind] - solve(ind+x, max(x, M), piles, suffix,dp));
           
        }    
        return dp[ind][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<vector<int>>dp (n, vector<int>(n+1, -1));
        vector<int> suffix(n+1, 0);


        for(int i=n-1; i>=0; i--){
            suffix[i] = suffix[i+1] + piles[i];
        }


        return solve(0, 1, piles, suffix, dp);

    }
};