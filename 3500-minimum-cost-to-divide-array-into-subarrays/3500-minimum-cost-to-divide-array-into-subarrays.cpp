class Solution {
public:
    typedef long long ll;    
    int K;
    int n;

    vector<ll> preSum;
    vector<ll> suffCost;    
    vector<ll> dp;
    
    ll solve(int start) {
        if(start == n) return 0;
        
        if(dp[start] != -1) {
            return dp[start];
        }
        
        ll ans = LLONG_MAX;
        for(int end = start; end < n; end++) {
            ll sumTillPos = preSum[end];
            ll currCost = suffCost[start];
            ll subarrayCost = suffCost[start] - (end + 1 < n ? suffCost[end + 1] : 0);
            ll cost = preSum[end] * subarrayCost + K   * currCost;
            
            ans = min(ans, cost + solve(end + 1));
        }
        
        return dp[start] = ans;
    } 
    
    long long minimumCost(vector<int> &nums, vector<int> &cost, int k) {
        n = nums.size();
        K = k;

        preSum.assign(n, 0);
        suffCost.assign(n, 0);

        preSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        
        suffCost[n - 1] = cost[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffCost[i] = suffCost[i + 1] + cost[i];
        }
        
        dp.assign(n+1, -1);
        return solve(0);
    }
};