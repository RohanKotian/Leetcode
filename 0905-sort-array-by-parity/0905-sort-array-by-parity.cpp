class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=0;

        while(j<nums.size()){
            if(nums[j] % 2){
                j++;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return nums;
    }
};