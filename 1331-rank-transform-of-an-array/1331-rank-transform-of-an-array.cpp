class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> res(n);
        vector<pair<int, int>> nums(n);

        if(n==0) return res;

        for(int i=0; i<n; i++){
            nums[i] = {arr[i], i};
        }

        sort(nums.begin(), nums.end());

        int rank = 1;

        res[nums[0].second] = 1;
        for(int i=1; i<n; i++){
            if(nums[i].first != nums[i-1].first){
                rank++;
            }
            res[nums[i].second] = rank;
        }
        return res;
    }
};