class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        
        for(int i=0; i<n; i++){
            int count = 1;        

            while(i<n-1 && nums[i] == nums[i+1]){
                i++;
                count++;
            }

            int val = min(count, k);
            for(int j=0; j<val; j++){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};