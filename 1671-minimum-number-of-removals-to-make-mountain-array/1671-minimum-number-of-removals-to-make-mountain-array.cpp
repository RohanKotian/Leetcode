class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        vector<int> res;
        res.push_back(nums[n-1]);

        for(int i=n-2; i>=0; i--){
            if(nums[i] > res.back()){
                res.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[ind] = nums[i];
            }
            dp2[i] = res.size();
        }

        res.clear();
        res.push_back(nums[0]);

        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i] > res.back()){
                res.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[ind] = nums[i];
            }
            dp1[i] = res.size();
            
            if(dp1[i] > 1 && dp2[i] > 1)
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        res.clear();
        dp1.clear();
        dp2.clear();

        return n - ans;
    }
};