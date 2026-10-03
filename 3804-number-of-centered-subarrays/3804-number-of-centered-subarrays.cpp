class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            unordered_set<int> st;

            for(int j=i; j<n; j++){
                sum += nums[j];
                st.insert(nums[j]);

                if(st.count(sum)){
                    res++;
                }
            }
        }
        return res;
    }
};