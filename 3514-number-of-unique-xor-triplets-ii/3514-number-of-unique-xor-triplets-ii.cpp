class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());

        int limit = 1;
        while(limit <= maxEle){
            limit <<= 1;
        }

        vector<bool> st1(limit, false);
        vector<bool> st2(limit, false);

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st1[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i=0; i<st1.size(); i++){
            if(st1[i]){
                for(int& num:nums){
                    st2[i ^ num] = true;
                }
            }
        }

        int count = 0;
        for(bool val:st2){
            if(val) count++;
        }
        
        return count;
    }
};