class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        int n = s.size();
        
        vector<long long> presum(n, 0);
        vector<long long> prenum(n, 0);
        vector<long long> pow10(n+1, 1);
        vector<int> count(n, 0);
        for(int i=1; i<=n; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }
        for(int i=0; i<n; i++){
            int digit = s[i] - '0';
            if(i>0){
                presum[i] = presum[i-1];
                prenum[i] = prenum[i-1];
                count[i] = count[i-1];
            }
            if(digit){
                presum[i] = (presum[i] + digit) % MOD;
                prenum[i] = (prenum[i] * 10 + digit) % MOD;
                count[i]++;
            }
        }
        vector<int> ans;
        for(auto& q:queries){
            int l = q[0];
            int r = q[1];
            
            long long sum = presum[r];
            long long num = prenum[r];
            int len = count[r];
            if(l>0){
                sum = (sum - presum[l-1] + MOD) % MOD; 
                int remove = count[l-1];
                int keep = len - remove;
                num = (num - prenum[l-1] * pow10[keep] % MOD + MOD) % MOD;
                len = keep;
            } 
            
            ans.push_back((num * sum) % MOD);
        }
        return ans;
    }
};