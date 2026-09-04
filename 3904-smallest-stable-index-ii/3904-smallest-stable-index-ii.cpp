class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minis(n);
        minis[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            minis[i] = min(minis[i+1], nums[i]);
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi - minis[i] <= k)
                return i;            
        }
        return -1;
    }
};