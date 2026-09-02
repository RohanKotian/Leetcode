class Solution {
public:
    int n;
    int findMaxLimit(int maxi){
        int maxLimit = 1;
        while(maxLimit<=maxi){
            maxLimit <<= 1;
        }
        return maxLimit--;
    }
    int solve(int i, int curr, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(i==n){
            if(curr==target)
                return 0;
            return 1e9;        
        }

        if(dp[i][curr] != -1) return dp[i][curr];

        int skip = solve(i+1, curr, nums, target, dp) + 1;
        int take = solve(i+1, curr ^ nums[i], nums, target, dp);

        return dp[i][curr] = min(skip, take);
    }

    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int maxLimit = findMaxLimit(maxi);

        vector<vector<int>> dp(n+1, vector<int>(maxLimit+1, -1));

        int res = solve(0, 0, nums, target, dp);
        return res >= 1e9 ? -1 : res;
    }
};