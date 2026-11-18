class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int amount, vector<int>& coins){
        if(i==n-1){
            if(amount % coins[i]==0){
                return amount / coins[i];
            }
            return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int skip = solve(i+1, amount, coins);
        int take = 1e9;
        if(amount - coins[i] >= 0){
            take = 1 + solve(i, amount - coins[i], coins);
        }

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        dp.assign(n, vector<int> (amount+1, -1));

        int res = solve(0, amount, coins);
        return res == 1e9 ? -1 : res;
    }
};