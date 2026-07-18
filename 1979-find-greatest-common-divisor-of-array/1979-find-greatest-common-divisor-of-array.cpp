class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = 1e9;
        int maxi = 1;
        for(int num:nums){
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        return std::gcd(mini, maxi);
    }
};