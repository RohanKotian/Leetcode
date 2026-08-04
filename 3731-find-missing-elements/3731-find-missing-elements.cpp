class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mini = nums[0], maxi = nums[nums.size()-1];

        vector<int> res;

        int seq = mini;
        for(int i=0; i<nums.size(); i++){
            if(seq==maxi) break;
            while(seq < nums[i]){
                res.push_back(seq);
                seq++;
            }
            if(seq==nums[i]){
                seq++;
            }
        }
        return res;
    }
};
