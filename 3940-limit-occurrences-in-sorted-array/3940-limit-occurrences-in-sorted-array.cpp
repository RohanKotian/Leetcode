class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int i = 0;
        while(i<n){
            int count = 1;        
            res.push_back(nums[i]);
            i++;

            while(i<n && nums[i-1] == nums[i] && count < k){
                res.push_back(nums[i]);
                i++;
                count++;
            }
            while(i<n && nums[i-1] == nums[i]){
                i++;
            }
        }
        return res;
    }
};