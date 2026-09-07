class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp, prev;

    int solve(int n){
        if(n==0)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int total = (2 * solve(n-1)) % MOD;

        if(prev[n]){
            int dups = solve(prev[n] - 1);
            total = (total - dups + MOD) % MOD;
        }

        return dp[n] = total;
    }
    
    int distinctSubseqII(string s) {    
        int n = s.size();
        dp.assign(n+1, -1);
        prev.assign(n+1, 0);

        int lastSeen[26] = {0};

        for(int i=1; i<=n; i++){
            int idx = s[i-1] - 'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + MOD) % MOD;
    }
};