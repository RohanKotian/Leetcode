class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        int i = 0;

        unordered_map<int, int> mp;
        for(int j=0; j<nums.size(); j++){
            mp[nums[j]]++;
            if(mp[nums[j]] <= k){
                res = max(res, j-i+1);
            }
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
        }
        return res;
    }
};