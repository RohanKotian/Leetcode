class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int pow = 1;
        while(n >= 1<<pow){
            pow++;
        }
        return 1<<pow;
    }
};