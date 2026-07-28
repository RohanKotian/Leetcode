class Solution {
public:
    void findCombos(int ind, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(temp);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            if(nums[i] > target) break;
            if(i > ind && nums[i-1]==nums[i]) continue;

            temp.push_back(nums[i]);
            findCombos(i+1, target-nums[i], nums, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        findCombos(0, target, candidates, temp, res);

        return res;
    }
};