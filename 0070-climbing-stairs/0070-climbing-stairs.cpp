class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(n<=2) return n;
        dp.resize(n+1);

        dp[0] = 1;
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1];
            if(i>1){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};